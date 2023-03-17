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

      #addi $t1, $zero, 1  # $s1 will register new previous value from $s2
      #addi $t0, $zero, 1  # $s2 will register new current value from $s3      

      #sw $t0 4($t1)


      # sll $t1, $s3, 2  #LMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOXLMAOBOX
      # add $t1, $t1, $s6
      # lw $t0, 0($t1)
      # addi $s3, $s3, 1
      # slt $t0, $s3, $s4
      # sw $t0, 4($s3)


li $a0, 10     #aaaaaaaaaaaaaaaaaaaaaaaaaaaa
not $t0, $t1   #bbbbbbbbbbbbbbbbbbbbbbbbbb
bge $s1, $s2, label #cccccccccccccccccccccccc
seq $t1, $t2, $t3 #dddddddddddddddddddddd



      # exit 
      li $v0, 10             #system call code for exit
      syscall                #executes exit
      # exit 
