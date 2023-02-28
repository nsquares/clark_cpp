#------------------------------------------------------------
# Asks for a number n. Then it calculates the fib series
#
# Register Usage Guide:
# $t0   n (input from user / also continue input)

# $s1   1   (first fib term)
# $s2   1   (second fib term)
# $s3   sum   (third fib term, the sum)

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
      li $v0, 4                             # Here, we load the value for our macro print_str
      la $a0, beginStr                          # We pass the argument with the string
      syscall                               # Print the string

      li $v0, 5                             # value for macro read_int
      syscall                               # Get integer
      move $t0, $v0    # $t0 = $v0, move out of syscall register into register that we control

      addi $t1, $zero, 1             # $t1=1 
      blt $t0, $t1, negative_case_error

      #for loop     
      addi $t2, $zero, 0    # for loop incrementor int i
      addi $s1, $zero, 0  # 1 2
      addi $s2, $zero, 1  # 1 3
      addi $s3, $zero, 1  # 1 3
loop: 
      li $v0, 1                        # value for the macro print_int
      move $a0, $s3     #print $s1
      syscall 

      #TODO: if n==2, loop back right here right now
      #beq 

      add $s3, $s2, $s1   #fib math for next term
      add $s1, $s2, $zero  #store
      add $s2, $s3, $zero  #store
      addi $t2, $t2, 1    #increment i

      # i == n
      beq $t2, $t0, skipDelimiter  #check if this is the last fib number, dont print delimiter
      
      li $v0, 4
      la $a0, delimStr   #print delimiter
      syscall
skipDelimiter:

      #slt $t3, $t2, $t0        # i < n 
      bne $t2, $t0, loop






      #continue statement
      li $v0, 4
      la $a0, continueStr
      syscall
      li $v0, 5   #read input
      syscall
      move $t0, $v0    # $t0 can be recycled here because end of program and will get new data at the beginning anyways
      bne $t0, $zero, main

      # exit 
      li $v0, 10                         #system call code for exit
      syscall                             #executes exit
      # exit 

negative_case_error:
      li $v0, 4                #print negative error str
      la $a0, negErrStr
      syscall

      j main                  #loop back to the beginning of the program

