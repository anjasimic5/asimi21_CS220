/*
long long sequence(long long n){  // changed to long long
    long long i = 1;   // changed to long long
    while(n != 1)
    {
        if (n % 2 == 0)
        {
            n = n /2;
        }
        else
        {
            n = 3 * n + 1;
        }
        i = i + 1;
    }
    
    return i;
}
*/

.cpu cortex-a53
.global sequence
.text

mod: 
    sdiv r2, r0, r1
    mul r2, r2, r1
    sub r0, r0, r2
    bx lr
    
sequence:
    push { r4, r5, r6, r7, lr }
    mov r4, #1 // i = 1
    mov r5, r0 // r5 = n
    mov r6, #2
    mov r7, #3
    
while:
    cmp r5, #1
    beq endwhile
    mov r0, r5
    mov r1, #2
    bl mod
    cmp r0, #0
    bne else
    sdiv r5, r5, r6 // n = n / 2
    add r4, r4, #1
    b while
    
else:
    mul r5, r5, r7 // n = 3 * n
    add r5, r5, #1 // n = n + 1
    add r4, r4, #1 // i++
    b while
    
endwhile:
    mov r0, r4
    pop { r4, r5, r6, r7, lr }
    bx lr
