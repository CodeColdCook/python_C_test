#!/bin/zsh
gcc test_func.cpp -o test_func -I/usr/include/python3.8 -lpython3.8

# error with 
# gcc test_1.c -o test_1 -I/usr/include/python3.6m -lpython3.6m