/*
unsigned int reverse(unsigned int n, unsidgned int r){
    if(n == 0)
        return r;
    else
        return reverse(n >> 1, (r << 1) | (n & 1));

}
*/ 

.cpu cortex-a53
.global reverse
.text

reverse:
    cmp r0, #0       // n == 0
    beq end
    lsr r2, r0, #1   // n >> 1
    lsl r1, r1, #1   // r << 1
    and r0, #1       // n & 1
    or r1, r0        // (r << 1) | (n & 1)
    mov r0, r2       // r0 = n >> 1
    b reverse
    
end:
    mov r0,  r1      // r0 = r
    bx lr



