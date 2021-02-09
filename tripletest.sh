#!/bin/bash

cd pft_2019
make re && ./test
cp ../libftprintf.a ../printf-tester/libftprintf.a
cd ../42TESTERS-PRINTF
bash runtest.sh
cd ../printf-tester
bash test.sh




