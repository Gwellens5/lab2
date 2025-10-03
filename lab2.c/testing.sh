#!/bin/bash
#Purpose:To provide test cases to test the durability of the program 
#Input:bash commands to test chill program
#Output:output of chill program 
# zero arguments                                                                    
./chill

# one argument                                                                      
./chill 32

# two arguments                                                                     
./chill 32.5 10

# temp out of range                                                                 
./chill 55

# wind out of range                                                                 
./chill 10 0

#too many arguments given
./chill 10 30 60

#temp out of range
./chill -99.0 5

#wind out of range
./chill 20 235

#temp as non numerical
./chill hello 23

#wind as non numerical 
./chill 12 hello
