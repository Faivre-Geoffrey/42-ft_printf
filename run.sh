#!/bin/bash

make re && gcc  main.c libft/libft.a libftprintf.a && make clean && ./a.out