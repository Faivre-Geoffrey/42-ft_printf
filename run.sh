#!/bin/bash

make re
clang -Wall -Wextra -Werror main.c libftprintf.a
make clean
valgrind ./a.out