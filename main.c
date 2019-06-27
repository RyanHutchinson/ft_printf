#include "incl/ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char 			c = 'A';
	char			*str = "String";
	int				i = -42;
	unsigned int	j = 42;

	printf("\n\n   printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%i|-|%o|-|%u|\n\n", &str, c, str, j, i, j, j);
	ft_printf("ft_printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%i|-|%o|-|%u|\n\n", &str, c, str, j, i, j, j);

// test
	return (0);
}