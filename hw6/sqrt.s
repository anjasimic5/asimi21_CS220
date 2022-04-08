/*
double fabs(double n) {
	if (n < 0)
	    n = -n;
	
	return n;
}

#define epsilon .0000001

double sqrt(double n){
	
	double r = n;   // initial guess at the root
	
	while(fabs(n - r*r) > epsilon){
		r = (r + n/r) / 2.0;
	}
	
	return r;
} */

.global sqrt
.global fabs
.cpu cortex-a53
.fpu neon-vfpv4
.text

fabs:
    ldr r0, =zero
    vldr.f64 d1, [r0]
    vcmp.f64 d0, d1
    vmrs APSR_nzvc, FPSCR    // copy floating-point flags to the integer CPU
    bgt end_fabs             // bgt uses the integer program status register
    ldr r0, =neg_one
    vldr.f64 d1, [r0]        // load -1.0 into d1
    vmul.f64 d0, d0, d1
    
end_fabs:
    bx lr
    
sqrt:
    push { lr }
    vpush { d8, d9 }
    vmov.f64 d8, d0        // r = n, d8 = n
    vmov.f64 d9, d8        // r is in d9
    
while:
    vmul.f64 d1, d9, d9    // d1 = r*r
    vsub.f64 d0, d8, d1    // n - r*r
    bl fabs                // fabs(n - r*r)
    ldr r0, =epsilon       
    vldr.f64 d1, [r0]      // d1 = epsilon
    vcmp.f64 d0, d1        // fabs(n - r*r) > epsilon 
    vmrs APSR_nzvc, FPSCR 
    ble end_while
    vdiv.f64 d2, d8, d9    // d2 = n/r
    vadd.f64 d2, d9, d2    // d2 = r + n/r
    ldr r0, =two
    vldr.f64 d1, [r0]
    vdiv.f64 d9, d2, d1    // r = (r + n/r) / 2.0
    bl while
    
end_while:
    vmov.f64 d0, d9
    vpop { d8, d9 }
    pop { lr }
    bx lr 
    
.data
.align 3
neg_one: .double -1.0
zero: .double 0.0
two: .double 2.0
epsilon: .double 0.00001
