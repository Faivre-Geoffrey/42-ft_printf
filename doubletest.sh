#!/bin/bash

cd pft_2019
make re && ./test
cd ../42TESTERS-PRINTF
bash runtest.sh
cd ..

