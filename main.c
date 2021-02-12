#include "ft_printf.h"
#define PRINT ("%-*p}", 8 ,&str)
#define PRINT2 ("%-*X}", -1,-22)

int main(void)
{

	char *str;


	ft_printf PRINT;
	printf("\n");
	printf PRINT;
	printf("\n");
	ft_printf PRINT2;
	printf("\n");
	printf PRINT2;

	return 0;
}
