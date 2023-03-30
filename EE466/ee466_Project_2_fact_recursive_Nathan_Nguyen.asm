#------------------------------------------------------------
# EE 466 Computer Architecture
# Spring 2023
# Dr. Chen Liu

# Project 2 Factorial - Recursive

# Nathan Nguyen
# 0942048
# Computer Engineering
# nguyennt@clarkson.edu
# 3/31/2023
# --------------------------------------------------------- 
#
#
# Register Usage Guide:
# $t0   n (input from user / also continue input)
# $t1   0   for negative input check 
#
# $  a number to multiply


            .data
beginStr:     .asciiz " Please enter a number >= 0 for n: "
negErrStr:    .asciiz "[n must be larger than or equal to 0.]\n"
continueStr:  .asciiz "\nDo you want to continue? Enter 1 (exit with 0): "
delimStr:    .asciiz ", "
            .text
            .globl main

main: 
    # FIRST THING: to do is create a stack frame for main (push stack)
    # (which is also technically a procedure)

    #stack ptr is pointing at the included last bottom word of the stack frame
    #frame ptr is pointing at the included first top word of the stack frame

    #stack frame address decreases in value when going down, "pushing the stack"

      subu      $sp, $sp, 32     # Stack frame is 32 bytes long, (push stack ptr down)
      sw        $ra, 20($sp)     # Save current return address (placed in "word 5" from bottom, which is where the stack ptr is == bottom of frame)
      sw        $fp, 16($sp)     # Save old frame pointer (placed in "word 4")
      addiu     $fp, $sp, 28     # Set up frame pointer (address here is +7 words up from the last word in frame that the $sp is pointing to)


    # ask user for n   
askUserN:   
      li $v0, 4                # load value for macro print_str
      la $a0, beginStr         # pass argument with beginning program string
      syscall                  # Print string

      li $v0, 5                # load value for macro read_int
      syscall                  # Get integer from user
      move $t0, $v0            # $t0 = $v0, move out of syscall register into register that we control

      addi $t1, $zero, 0       # $t1=0 (used to determine negative input case [n should be >= 0])
      blt $t0, $t1, negative_case_error  # if n < 0, branch to negative input case error handler section

      add $a0, $t0, $zero      # move/pass n as an argument to factorial function
    # factorial recursive function start (call fact)
      jal fact   # jump/goto the factorial function 
                 # and store address pointing to the 
                 # first instruction in the continue statement block 
                 # right below here 
                 # into $ra (return address reg)

    # print result here, $v0 has the answer from fact
      move $a0, $v0         # copy $v0 value into a syscall argument reg
      li $v0, 1             # load value for macro print_int
      syscall               # print value from $v0 



    # continue statement block
      li $v0, 4              # load value for macro print_str    
      la $a0, continueStr    # pass argument the continue string
      syscall                # print text
      li $v0, 5              # load value for macro read_int
      syscall                # Get integer from user
      move $t0, $v0          # $t0 = $v0, move out of syscall register into register that we control
                             # $t0 can be recycled here because end of program and will get new data at the beginning anyways
      bne $t0, $zero, askUserN   # check user input and if (n != 0), we restart the program, from the very beginning
                             # Anything other than 0 triggers restart

    # LAST THING: free up space (restore stack) 
    # taken from main (pop stack)
      lw        $ra, 20($sp)     # Restore return address 
      lw        $fp, 16($sp)     # Restore frame pointer 
      addiu     $sp, $sp, 32     # Pop stack frame 
      jr        $ra              # Return to caller of procedure main
      #this might not be needed and will be handled by spim, might add
      #back just to see what would happen anyways


      # exit (not needed, can just "jr $ra" )
      #li $v0, 10             #system call code for exit
      #syscall                #executes exit
      # exit 

negative_case_error:
      li $v0, 4               # load value for macro print_str
      la $a0, negErrStr       # pass argument the continue string
      syscall                 # print negative error str

      j askUserN              # jump back to the beginning of the program




fact:
    # push stack (create stack frame)
      subu      $sp, $sp, 32     # Stack frame is 32 bytes long  
      sw        $ra, 20($sp)     # Save return address  
      sw        $fp, 16($sp)     # Save frame pointer  
      addiu     $fp, $sp, 28     # Set up frame pointer  
      
      sw        $a0, 0($fp)      # Save argument (n) into new fact stack frame
                                 # placed in topmost word of current frame

      lw        $v0, 0($fp)      # Load n into result reg
      bgtz      $v0, fact_logic  # Branch if n > 0 
      li        $v0, 1           # else Return 1 
      jr        fact_returning   # Jump to code for returning out of fact function

fact_logic:
      lw        $v1, 0($fp)      # Load n 
      subu      $v0, $v1, 1      # Compute n - 1 
      move      $a0, $v0         # Move value to $a0
      jal       fact             # Call factorial function
      lw        $v1, 0($fp)      # Load n 
      mul       $v0, $v0, $v1    # Compute fact(n-1) * n

fact_returning:
      # pop stack (free up space)
      # Result is in $v0 
      lw        $ra, 20($sp)     # Restore $ra 
      lw        $fp, 16($sp)     # Restore $fp 
      addiu     $sp, $sp, 32     # Pop stack 
      jr        $ra              # Return to caller

