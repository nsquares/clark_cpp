#------------------------------------------------------------
# EE 466 Computer Architecture
# Spring 2023
# Dr. Chen Liu

# Project 3 Sorting Algorithm

# Nathan Nguyen
# 0942048
# Computer Engineering
# nguyennt@clarkson.edu
# 4/21/2023

# --------------------------------------------------------- 
#
#
# Register Usage Guide (in main):
# $t0  i=0, for loop print incrementer
# $s0  arraySize value (subtract this by 1 because i starts at zero)
# $s1  base address of array



            .data
beginStr:     .asciiz "The original array is:\n"
endStr:       .asciiz "\nThe sorted array is:\n"
inArray:      .word 4, 1, 3, 2, 16, 9, 10, 14, 8, 7
arraySize:    .word 10
# inArray:      .word 19, 11, 24, 12
# arraySize:    .word 4
# inArray:      .word 30, 8, 2, 13, 7, 18, 14, 20, 4
# arraySize:    .word 9
delimStr:     .asciiz ", "
            .text
            .globl main


main: #handles input and output

    # FIRST THING: to do is create a stack frame for main (push stack)

    #frame ptr is pointing at the included first top word of the stack frame
    #stack ptr is pointing at the included last bottom word of the stack frame

    #stack frame address decreases in value when going down, "pushing the stack"

    subu      $sp, $sp, 32     # Stack frame is 32 bytes long, (push stack ptr down)
    sw        $ra, 20($sp)     # Save current return address (placed in "word 5" from bottom, which is where the stack ptr is == bottom of frame)
    sw        $fp, 16($sp)     # Save old frame pointer (placed in "word 4")
    sw        $s0, 12($sp)     # Saving old s0
    sw        $s1, 8($sp)      # Saving old s1  (reqiurement for all procedures, save saved registers)
    #sw        $s2, 4($sp)      # Saving old s2
    addiu     $fp, $sp, 28     # Set up frame pointer (address here is +7 words up from the last word in frame that the $sp is pointing to)

    #display hard-coded input array:
    li $v0, 4                # load value for macro print_str
    la $a0, beginStr         # pass argument with beginning program string
    syscall                  # Print string

    #init key registers:
    lw $s0, arraySize     # load arraySize and this holds array size ($s0)    
    #addi $s2, $s0, -1     # subtract by 1 for finding when to skipDelimiter 
    addi $t0, $zero, 0    # for loop incrementor (int i = 0)
    la $s1, inArray       # load base address of array
printLoop:
    #load array element from memory for print
    sll $t1, $t0, 2       # calculate byte addressable offset (i*4)
    add $t1, $t1, $s1     # base address + offset
    lw $a0, 0($t1)        # load from memory to a syscall argument reg    
    li $v0, 1             # load value for macro print_int        
    syscall               # print array

    addi $t0, $t0, 1  #increment i    
    
    beq $t0, $s0, skipDelimiter #check if this is the last element in the array to print, dont print delimiter
    li $v0, 4          # load value for macro print_str
    la $a0, delimStr   # pass argument the delimiter string
    syscall            # print delimiter
skipDelimiter:    
    bne $t0, $s0, printLoop #if (i != (arraySize)) loop again to print next element in array

    #" "main" calls two procedures, "swap" and "sort" "
    #add $a1, $s0, 1
    move $a0, $s1  #pass base addr of array
    move $a1, $s0  #pass arraySize raw value
    jal sort       #calling sort procedure, jump and link

    #display output array:
    li $v0, 4                # load value for macro print_str
    la $a0, endStr           # pass argument with ending program string
    syscall                  # Print string

    addi $t0, $zero, 0    # for loop incrementor (int i = 0)
printLoop2:
    #load array element from memory for print
    sll $t1, $t0, 2       # calculate byte addressable offset (i*4)
    add $t1, $t1, $s1     # base address + offset
    lw $a0, 0($t1)        # load from memory to a syscall argument reg    
    li $v0, 1             # load value for macro print_int        
    syscall               # print array

    addi $t0, $t0, 1  #increment i    

    beq $t0, $s0, skipDelimiter2 #check if this is the last element in the array to print, dont print delimiter
    li $v0, 4          # load value for macro print_str
    la $a0, delimStr   # pass argument the delimiter string
    syscall            # print delimiter
skipDelimiter2:
    bne $t0, $s0, printLoop2 #if (i != (arraySize)) loop again to print next element in array

    # LAST THING: free up space (restore stack) 
    # taken from main (pop stack)
    lw        $ra, 20($sp)     # Restore return address 
    lw        $fp, 16($sp)     # Restore frame pointer 
    lw        $s0, 12($sp)     # Restore old s0
    lw        $s1, 8($sp)      # Restore old s1
    #lw        $s2, 4($sp)      # Restore old s2
    addiu     $sp, $sp, 32     # Pop stack frame 
    jr        $ra              # Return to caller of procedure main

    #------------------------------------------------
sort:
    addi $sp, $sp, -32 # make room for 8 registers on stack
    sw $fp, 20($sp)    # saving old frame pointer on stack
    sw $ra, 16($sp)    # saving $ra on stack
    sw $s3, 12($sp)    # saving $s3 on stack
    sw $s2, 8($sp)     # saving $s2 on stack
    sw $s1, 4($sp)     # saving $s1 on stack
    sw $s0, 0($sp)     # saving $s0 on stack
    addiu $fp, $sp, 28     # Set up frame pointer

    move $s2, $a0 # copy parameters over (save them) (base address of array)
    move $s3, $a1 # copy parameters over (save them) (arraySize)

    move $s0, $zero  # i=0      
for1tst:
    slt $t0, $s0, $s3  # s3 is the arraySize, (i<arraySize)
    beq $t0, $zero, exit1 # if (i<arraySize) is not the case any more, exit outer loop

    addi $s1, $s0, -1  # j=i-1      
for2tst:
    slti $t0, $s1, 0       # j>=0
    bne $t0, $zero, exit2  # not equal, to support >=
    sll $t1, $s1, 2        # j*4
    add $t2, $s2, $t1      # (base addr + (j*4)) == new addr
    lw $t3, 0($t2)         # v[j] == $t3
    lw $t4, 4($t2)         # v[j+1] == $t4
    slt $t0, $t4, $t3      # v[j] > v[j+1]
    beq $t0, $zero, exit2  # equal, to support the less than condition above 
    
    move $a0, $s2       # pass base addr 
    move $a1, $s1       # pass j value
    jal swap            # call swap procedure, jump and link

    addi $s1, $s1, -1 # j -= 1
    j for2tst         # inner-looping

exit2:
    addi $s0, $s0, 1  # increment i
    j for1tst         # outer-looping

exit1:      
    lw $ra, 16($sp)   # restore $ra from stack
    lw $s3, 12($sp)   # restore $s3 from stack
    lw $s2, 8($sp)    # restore $s2 from stack
    lw $s1, 4($sp)    # restore $s1 from stack
    lw $s0, 0($sp)    # restore $s0 from stack            
    lw $fp, 20($sp)   # Restore frame pointer 
    addi $sp, $sp, 32 # restore stack pointer, pop stack
    
    jr $ra #return to procedure that called sort


    # if the procedure never uses stored registers,
    # then no need to create stack.
    # temp registers can be used freely and
    # are assumed to be lost data when a procedure is called
    
    # Also, since this is a leaf procedure, like it
    # will not call on another procedure, then it does 
    # not need to store its return address register
    # (Therefore, a stack frame is needed if non-leaf procedure no matter what)
swap:
    sll $t1, $a1, 2  # k*4
    add $t1, $a0, $t1 # (base addr + (k*4)) == v[k] == $t1
    
    lw $t0, 0($t1) # t0 is temp and gets v[k]
    lw $t2, 4($t1) # t2 == v[k+1]

    sw $t2, 0($t1) # store back into data memory
    sw $t0, 4($t1) # (the sort procedure changes the data segment off-chip memory permanently) swap position in memory, two elements of the array, using temp variable

    jr $ra #return to procedure that called swap

