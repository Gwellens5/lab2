#!/bin/bash
#Purpose:To provide test cases to test the durability of the program 
#Input:bash commands to test histo program
#Output:output of histo program 
#Name: Garrett Wellens cs50 25f

#No input
echo | ./histo
#not growing array --> constant bin size
echo 1 2 3 4 5 8 9 10 12 14 12 | ./histo
#Growing bin size
echo 128 | ./histo
#Grow multiple times
echo 22 33 44 1000 876 90 | ./histo
#Ignore negatve number
echo -30 67 99 10 12 | ./histo
#no valid input
echo *@ | ./histo