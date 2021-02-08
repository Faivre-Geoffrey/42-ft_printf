#include "ft_printf.h"
#define PRINT ("%*.*i}",-2,-2, 2)
#define PRINT2 ("%*.*i}",-2,2,2)

int main(void)
{


	ft_printf PRINT;
	printf("\n");
	printf PRINT;
	printf("\n");
	ft_printf PRINT2;
	printf("\n");
	printf PRINT2;

	return 0;
}
