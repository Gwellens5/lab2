#!/bin/bash
#Purpose:To provide test cases to test the durability of the program 
#Input:bash commands to test words program
#Output:output of words program 
#Name: Garrett Wellens cs50 25f

#test empty input
echo | ./words 
#test a non alpha input
echo "1 2 3 4 5 ^ ** $) (2343)" | ./words
#test input with punctuation
echo "Hello my name is Garrett, nice to meet you!!" | ./words
#test reasonable input
echo "I cannot believe it" | ./words
#test weirdly placed non alpha chars stuff 
echo "Hello123*#&$ dogs cats7cating" | ./words 
#testing large file
./words text.txt
#testing two files
./words words.txt words-tx.txt
#testing unopenable file
./words wellens.txt
#testing mixed file
./words words.c
