/*
int sum3or5(int n)
{
    int sum = 0, i = 1;
    while(i < n)
    {
        if (i%3 == 0 || i%5 == 0)
        {
            sum = sum + i;
            i = i + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    
    return sum;
}
*/

.cpu cortex-a53
.global sum3or5
.text

mod: 
    sdiv r2, r0, r1
    mul r2, r2, r1
    sub r0, r0, r2
    bx lr

sum3or5:
    push { r4, r5, r6, lr }
    mov r4, #0 // sum = 0
    mov r5, #1 // i = 1
    mov r6, r0

while:
    cmp r5, r6
    bge endwhile
    mov r0, r5
    mov r1, #3
    bl mod
    cmp r0, #0
    bne or
    add r4, r4, r5
    add r5, r5, #1
    b while
    
or:
    mov r0, r5
    mov r1, #5
    bl mod
    cmp r0, #0
    bne else
    add r4, r4, r5
    add r5, r5, #1
    b while
    
else:
    add r5, r5, #1
    b while
    
endwhile:
    mov r0, r4
    pop {r4, r5, r6, lr}
    bx lr
