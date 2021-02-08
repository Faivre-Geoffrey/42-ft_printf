#!/bin/bash

make re && gcc -Wall -Wextra -Werror main.c libft/libft.a libftprintf.a && make clean && ./a.out