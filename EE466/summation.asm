#------------------------------------------------------------
# sum.s
# Asks for a number i. Then it calculates the sum of all numbers
# from 1 to i
# Register Usage:
# $t0 sum (the sum)
# $t1 i (loop index)
# $t2 testing if i>=1
# $t3 1
# Algorithm in c:
#
# int i,sum;
# scanf ("Please enter a number>=1",&i);
# if (i>=1)
# { 
# sum = 0; 
# while (i>=1)
# {
# sum = sum + i;
# i = i - 1;
# }
# printf ("The result is: %d", sum);
# }
#-----------------------------------------------------------

            .data
str1:     .asciiz " Please enter a number >= 1 : "
str2:     .asciiz "\n\n The result is:" 
            .text
            .globl main

main: 
            li $v0, 4                             # Here, we load the value for our macro print_str
            la $a0, str1                        # We pass the argument with the string
            syscall                               # Print the string

            li $v0, 5                             # value for macro read_int
            syscall                               # Get integer
            move $t1, $v0                   # $t1 = $v0

            addi $t3, $zero, 1             # $t3=1 
            slti $t2, $t1, 1                   # if $t1<1 then $t2=1 else $t2=0
            beq $t3, $t2, do_nothing  # if $t2==1 do nothing


            addi $t0, $0, 0               # sum = 0 
loop: 
            sge $t2, $t1, $t3             # if $t1>=1 then $t2=1 else $t2=0
            beq $t2, $zero, end        # if $t2!=1 exit 

            add $t0, $t0 , $t1           # sum = sum + i
            addi $t1, $t1 , -1            # i = i - 1
            j loop

end:
            li $v0, 4                        # Here, we load the value for our macro print_str
            la $a0, str2                   # We pass the argument with the string
            syscall                          # Print the string

            li $v0, 1                        # value for the macro print_int
            move $a0, $t0              # move $t0 to the argument 
            syscall 

do_nothing:

           li $v0, 10                         #system call code for exit
           syscall                             #executes exit
