/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:54:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/17 08:38:25 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	checktype(const char *fmt, va_list ap)
{
	if (fmt[1] == '%')
		ft_putchar('%');
	if (fmt[1] == 'd' || fmt[1] == 'i')
	{
		if(fmt[2] == '0' && fmt[3] != 'x')
			ft_putstr(ft_itoa_base(va_arg(ap, int), 8));
		else
			ft_putnbr(va_arg(ap, int));
	}
	if (fmt[1] == 'u')//<------------------------------------------------------ I am not sure of wtf should happen here.... it works but does not !work when a !unsigned-int is passed.
		ft_putnbr(va_arg(ap, unsigned int));
	if (fmt[1] == 'x' || fmt[1] == 'X')
	{
		char	*tmp;

		tmp = ft_itoa_base((long)va_arg(ap, unsigned int), 16);
		if(fmt[1] == 'X')
			ft_putstr(ft_strtoupper(tmp));
		else
			ft_putstr(tmp);
	}
	if (fmt[1] == 'o')
		ft_putstr(ft_itoa_base((long)va_arg(ap, unsigned int), 8));
	if (fmt[1] == 's')
		ft_putstr(va_arg(ap, char *));
	if (fmt[1] == 'c')
		ft_putchar(va_arg(ap, int));
	if (fmt[1] == 'p')
		ft_putstr(ft_strjoin("0x", ft_itoa_base((long)va_arg(ap, void*), 16)));
	return (1);
}

int	paramchecker(const char *fmt, va_list ap)
{
	int	i;
	//i = checkflags(); ------------------------------------------------------- Check the flags and do the things.
	//i = checkwidth(); ------------------------------------------------------- Check total printable width and do stuff.
	//i = checklength(); ------------------------------------------------------ Check the.... man, things happen here.
	i = checktype(fmt, ap);
	return(i);
}

int	ft_printf(const char *fmt, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			ft_putchar(fmt[i]);
		if (fmt[i] == '%')
			{
				if (fmt[i + 1] == 'n')//--------------------------------------- You need to have a re-think about printed character tracking...
				{
					int *ptr;
					
					ptr = va_arg(ap, int*);
					*ptr = i;
				}
				i += paramchecker(&fmt[i], ap);
			}
		i++;
	}
	va_end(ap);
	return (0);
}
/************************************************************************************/
/*************************************THE MAIN***************************************/
/************************************************************************************/
int	main(void)
{
	char 			c = 'A';
	char			*str = "String";
	int				i = 0;
	scanf("%d", &i);
	unsigned int	j = 42;

	printf("\n\n   printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%i|-|%o|\n\n", &str, c, str, j, i, j);
	ft_printf("ft_printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%i|-|%o|\n\n", &str, c, str, j, i, j);


	printf("FUCK");

	return (0);
}