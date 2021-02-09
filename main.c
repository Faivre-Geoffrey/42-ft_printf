#include "ft_printf.h"
#define PRINT ("%*i}", -23)
#define PRINT2 ("%-*.*i}",-2,5,2)

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
