#!/bin/zsh
gcc test_1.c -o test_1 -I/usr/include/python2.7 -lpython2.7 

# error with 
# gcc test_1.c -o test_1 -I/usr/include/python3.6m -lpython3.6m