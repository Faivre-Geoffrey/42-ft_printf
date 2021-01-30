#include "ft_printf.h"
#define PRINT ("[%p]",str)
int main(void)
{
	char *str = malloc(sizeof(char) * 2);
	ft_printf PRINT;
	printf("\n");
	printf PRINT;
	return 0;
}
