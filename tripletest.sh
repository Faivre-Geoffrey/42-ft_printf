#!/bin/bash

git clone https://github.com/AntoineBourin/printf-tester.git
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
cd ..
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git

cd pft_2019
make re && ./test
cp ../libftprintf.a ../printf-tester/libftprintf.a
cd ../42TESTERS-PRINTF
bash runtest.sh
cd ../printf-tester
bash test.sh
cd ..

rm -rf pft_2019
rm -rf 42TESTERS-PRINTF
rm -rf printf-tester

norminette -R CheckForbiddenSourceHeader
