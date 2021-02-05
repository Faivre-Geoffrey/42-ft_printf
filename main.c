#include "ft_printf.h"
#define PRINT ("%05i}",2)
#define PRINT2 ("%.5i}",2)
#define PRINT3 ("%-0-0-0-0-.*d}",12,-12)
#define PRINT4 ("%-----.*d}",2,-12)
int main(void)
{


	ft_printf PRINT;
	printf("\n");
	printf PRINT;
	printf("\n");
	ft_printf PRINT2;
	printf("\n");
	printf PRINT2;
	printf("\n");
	ft_printf PRINT3;
	printf("\n");
	printf PRINT3;
	printf("\n");
	ft_printf PRINT4;
	printf("\n");
	printf PRINT4;
	return 0;
}
