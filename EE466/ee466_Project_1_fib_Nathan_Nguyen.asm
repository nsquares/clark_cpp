#------------------------------------------------------------
# EE 466 Computer Architecture
# Spring 2023
# Dr. Chen Liu
#
# Project 1 Fibonacci Numbers
#
# Nathan Nguyen
# 0942048
# Computer Engineering
# nguyennt@clarkson.edu
# 3/3/2023
# 
# --------------------------------------------------------- 
# 
# Asks for a number n. Then it calculates numbers in the fib series up to n terms
#
# Register Usage Guide:
# $t0   n (input from user / also continue input)
#
# $s1   0   (first fib term)
# $s2   1   (second fib term)
# $s3   sum   (third fib term, the sum)
#
# $t1   1   for negative input check 
# $t2   i   for loop 
# $t3   hold for loop less than comparsion
#-----------------------------------------------------------

            .data
beginStr:     .asciiz " Please enter a number >= 1 for n: "
negErrStr:    .asciiz "[n must be larger than or equal to 1.]\n"
continueStr:  .asciiz "\nDo you want to continue? Enter 1 (exit with 0): "
delimStr:    .asciiz ", "
            .text
            .globl main

main: 
      li $v0, 4                # load value for macro print_str
      la $a0, beginStr         # pass argument with beginning program string
      syscall                  # Print string

      li $v0, 5                # load value for macro read_int
      syscall                  # Get integer from user
      move $t0, $v0            # $t0 = $v0, move out of syscall register into register that we control

      addi $t1, $zero, 1       # $t1=1 (used to determine negative input case [n should be >= 1])
      blt $t0, $t1, negative_case_error  # if n < 1, branch to negative input case error handler section

      #start of for loop     
      addi $t2, $zero, 0    # for loop incrementor (int i = 0)
      addi $s1, $zero, 0    # initialize $s1 reg to hold 0 to handle n=1 and n=2 case, no need for printing 1 twice
      addi $s2, $zero, 1    # initialize $s2 reg to hold 1
      addi $s3, $zero, 1    # initialize $s3 reg to hold 1 (register that will be printed)
                            # (hold 1 for printing 1 in n=1 case)
loop: 
      li $v0, 1             # load value for macro print_int
      move $a0, $s3         # copy $s3 value into a syscall argument reg
      syscall               # print value from $s3 

      add $s3, $s2, $s1    # fib add for next term 
      add $s1, $s2, $zero  # $s1 will register new previous value from $s2
      add $s2, $s3, $zero  # $s2 will register new current value from $s3
      addi $t2, $t2, 1     # increment i to keep track of how many times we have looped/printed a number

      # if i == n, skip printing comma
      beq $t2, $t0, skipDelimiter  #check if this is the last fib number, dont print delimiter
      
      li $v0, 4          # load value for macro print_str
      la $a0, delimStr   # pass argument the delimiter string
      syscall            # print delimiter
skipDelimiter:

      #slt $t3, $t2, $t0     # i < n  # not really needed, less instructions
      bne $t2, $t0, loop     # if (i != n), loop, else we equal and we are done
      #end of for loop


      #continue statement
      li $v0, 4              # load value for macro print_str    
      la $a0, continueStr    # pass argument the continue string
      syscall                # print text
      li $v0, 5              # load value for macro read_int
      syscall                # Get integer from user
      move $t0, $v0          # $t0 = $v0, move out of syscall register into register that we control
                             # $t0 can be recycled here because end of program and will get new data at the beginning anyways
      bne $t0, $zero, main   # check user input and if (n != 0), we restart the program, from the very beginning
                             # Anything other than 0 triggers restart

      # exit 
      li $v0, 10             #system call code for exit
      syscall                #executes exit
      # exit 


negative_case_error:
      li $v0, 4               # load value for macro print_str
      la $a0, negErrStr       # pass argument the continue string
      syscall                 # print negative error str

      j main                  # jump back to the beginning of the program

