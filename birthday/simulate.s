// static variables are stored in global memory
// local variables not allcoated to registers are stored on the stack
// The read-modify-write operation is a fundamental computer science  concept
//    ldr, modify, str

// ldr, str. The ARM processor is called a load/store architecture
// all operations happen in register that are loaded from memory 
// and then stored.

/* int simulate(int n){
	const int DAYS = 366;
	int cal[DAYS];
	// a static variable retains its value (and memory)
	// across function calls
	static int seedhack = 0;
	srand(time(NULL) + seedhack++);	
	memset(cal, 0, DAYS*sizeof(int)); //integer is a dif num of bytes depending on the machine	
	// assign n birthdays
	int i = 0;
	while(i < n) {
		cal[rand() % DAYS]++;
		i++;
	}	
	i = 0;
	while(i < DAYS){
		if(cal[i] > 1)
		    return 1;
		i++;
	}
	return 0;
}
*/

.global simulate
.cpu cortex-a53
.data // allocate global memory

// a word is the width, in bytes, of the natural size of the machine
// 4 bytes
seedhack: .word 0

.text

mod: 
    sdiv r2, r0, r1
    mul r2, r2, r1
    sub r0, r0, r2
    bx lr

simulate:
    push { r4 - r8, lr }
    mov r6, #366
    mov r5, r0
    
    // local variables get stored on the stack if you can't put them
    // in a register
    sub sp, sp, r6, lsl #2  // shift r6 by two and then subtract
    mov r7, sp              // store starting address of array in r7
    ldr r4, =seedhack       // put the address of seedhack in r4
    
    // read-modify-write
    ldr r8, [r4]            // get the value of seedhack 
    add r8, r8, #1
    str r8, [r4]            // put incremented value back in seedhack
    
    // call time
    mov r0, #0
    bl time
    add r0, r0, r8
    bl srand
    
    // set up call to memset
    mov r0, r7
    mov r1, #0
    mov r2, r6, lsl #2
    
    //bl memset
    
    mov r8, #0          // i = 0
    
// note: use r7 instead of sp
while1:
    cmp r8, r5          // i < n
    bge endwhile1  
    bl rand             // r0 = rand()
    mov r1, r6          // r1 = 366
    bl mod              // r0 = rand() % DAYS
    lsl r0, r0, #2      // to find the address
    add sp, sp, r0      
    ldr r0, [sp]        // load into register then put back
    add r0, r0, #1      // cal[rand() % DAYS]++ 
    str r0, [sp]
    mov sp, r7          // sp back to where it was
    add r8, r8, #1      // i++
    bl while1
     
    
endwhile1:
    mov r8, #0          // i = 0
    
while2:
    cmp r8, r6          // i < 366
    bge endwhile2       //
    lsl r0, r8, #2      // get the address
    add sp, sp, r0      // sp points to that address
    ldr r2, [sp]        // load what's on the address
    cmp r2, #1          // check cal[i] > 1
    bgt endend
    mov sp, r7          // sp back to where it was
    add r8, r8, #1      // i++
    bl while2
    
endwhile2:
    mov r0, #0
    pop { r4 - r8, lr}
    bx lr

endend:
    mov r0, #1
    pop { r4 - r8, lr}
    bx lr

    // Finish for HW :-))))


