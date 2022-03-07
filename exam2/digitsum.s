/*
int digitsum(int n){
    int sum = 0;
    while(n!=0) {
    sum = sum + n % 10;
    n = n / 10;
    }
    
    return sum;
}
*/

.cpu cortex-a53
.global digitsum
.text

mod: 
    sdiv r2, r0, r1
    mul r2, r2, r1
    sub r0, r0, r2
    bx lr

digitsum:
    push { r4, r5, r6, lr}
    mov r4, r0 // r4 = n
    mov r5, #0 // sum = 0
    mov r6, #10
while:
    cmp r4, #0 // n!=0
    beq endwhile
    mov r0, r4
    mov r1, r6
    bl mod // r0 = n%10
    add r5, r5, r0 // sum = sum + n%10
    sdiv r4, r4, r6 // n = n/10
    b while
    
endwhile:
    mov r0, r5
    pop { r4, r5, r6, lr }
    bx lr


