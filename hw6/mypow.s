/*
int mypow(int x, int y) {
	
	if(y == 0)
	    return 1;
	    
	else if(y % 2 == 0) {
		return mypow(x, y/2.0) * mypow(x, y/2.0);
	}
	
	else{
		return mypow(x, y-1) * x;
	}
	
} */

.global mypow
.cpu cortex-a53
.text


mod: 
    sdiv r2, r0, r1
    mul r2, r2, r1
    sub r0, r0, r2
    bx lr

mypow:
    push { r4 - r7 , lr}
    mov r4, r0      // r4 = x
    mov r5, r1      // r5 = y
    mov r6, #0     
    cmp r5, r6      // y == 0
    beq if1
    mov r1, #2
    mov r0, r5
    bl mod          // y % 2
    cmp r0, r6      // y % 2 == 0
    beq if2
    bne else
    
    
if1:
    mov r0, #1
    pop { r4 -r7, lr}
    bx lr              // return
    
if2:
    mov r1, #2  
    sdiv r1, r5, r1    // y = y / 2
    mov r0, r4
    bl mypow           // mypow(x, y/2)
    mov r7, r0
    mov r1, #2
    sdiv r1, r5, r1
    mov r0, r4
    bl mypow           // mypow(x, y/2)
    mul r0, r0, r7     // mypow(x, y/2) ^ 2
    pop { r4 - r7, lr}
    bx lr              // return
    
else:
    mov r0, r4
    sub r1, r5, #1     // y = y - 1 
    bl mypow           // mypow(x, y - 1)
    mul r0, r0, r4     // mypow(x, y - 1) * x
    pop { r4 - r7, lr }
    bx lr              // return
    
