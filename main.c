#include <stdio.h>
#include "ft_printf.h"

int main()
{
	 int test = 42 ; 


	
	  ft_printf("bonjour\n") ;
    ft_printf("char:                    %-5.3n\n", 'r') ; 
     ft_printf("string:                  %-5.3s\n", "bonjour") ;
	 printf("string:                  %-5.3s\n", "bonjour");
      ft_printf("pointer:                 %-5.3p\n", &test) ;
      ft_printf("int:                     %-5.3d \n", 54) ;
     ft_printf("uint:                    %-5.3u\n", 31) ;
     ft_printf("hex lower:               %-5.3x\n", 0xabcf012) ;
     ft_printf("hex upper:               %-5.3X\n", 0xabcf012) ;
     ft_printf("percent:                 %%\n") ;
	 ft_printf("multiple stuff:          %-5.3d %-5.3u %-5.3d %-5.3x %-5.3d\n", 1, -2, 3, 0xa, 5) ;
	 ft_printf("s,dhghasfggfasff TTTTTTTEEEESSSSTTTT\n") ;
    return 0;
}