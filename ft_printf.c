/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:54:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/17 13:57:23 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//you need to do the stuff to make wide chars do things.

#include <stdio.h>
#include "ft_printf.h"

t_format	*ft_newformat()
{
	t_format *new;

	if(!(new = malloc(sizeof(t_format))))
		return (NULL);
	new->leftpad = 0;
	new->rightpad = 0;
	new->zero = 0;
	new->sign = '0';
	new->hash = '0';
	return(new);
}

int	isconversion(const char fmt)
{
	return(fmt == '%' || fmt == 'i' || fmt == 'd' || fmt == 'D' || fmt == 'u' || fmt == 'U' || fmt == 'x' || fmt == 'X' || fmt == 'o' || fmt == 'O' || fmt == 's' || fmt == 'c' || fmt == 'p');
}

int	checkflags(const char *fmt, t_format *format)
{
	int i;

	i = 1;
	if (fmt[i] == '+' && !(isconversion(fmt[3])))
	{
		format->sign = 's';
		i++;
	}
	return(i);
}

// damnit I get now why you would want to store all the fomatting into a table. I need to have a rethink.

int		checktype(const char *fmt, va_list ap, int i)
{
	if (fmt[i] == '%')
		ft_putchar('%');
	if (fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i')
	{
		if(fmt[i + 1] == '0' && fmt[i + 2] != 'x')
			ft_putstr(ft_itoa_base(va_arg(ap, int), 8));
		else
			ft_putnbr(va_arg(ap, int));
	}
	if (fmt[i] == 'u' || fmt[i] == 'U')
		ft_putnbr(va_arg(ap, unsigned int));
	if (fmt[i] == 'x' || fmt[i] == 'X')
	{
		char	*tmp;

		tmp = ft_itoa_base((long)va_arg(ap, unsigned int), 16);
		if(fmt[i] == 'X')
			ft_putstr(ft_strtoupper(tmp));
		else
			ft_putstr(tmp);
	}
	if (fmt[i] == 'o' || fmt[i] == 'O')
		ft_putstr(ft_itoa_base((long)va_arg(ap, unsigned int), 8));
	if (fmt[i] == 's')
		ft_putstr(va_arg(ap, char *));
	if (fmt[i] == 'c')
		ft_putchar(va_arg(ap, int));
	if (fmt[i] == 'p')
		ft_putstr(ft_strjoin("0x", ft_itoa_base((long)va_arg(ap, void*), 16)));
	return (i - 1); //still to be fixed
}

int	paramchecker(const char *fmt, va_list ap, t_format *format)
{
	int	i;
	i = 0;
	i += checkflags(fmt, format);
	//i = checkwidth(); ------------------------------------------------------- Check total printable width and do stuff.
	//i = checklength(); ------------------------------------------------------ Check the.... man, things happen here.
	i += checktype(fmt, ap, i);
	return(i);
}

int	ft_printf(const char *fmt, ...)
{
	int	i;
	va_list	ap;
	t_format *format;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		format = ft_newformat();
		if (fmt[i] != '%')
			ft_putchar(fmt[i]);
		if (fmt[i] == '%')
			{
				i += paramchecker(&fmt[i], ap, format);
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
	int				i = 0x2A;
	unsigned int	j = 42;

	printf("\n\n   printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%+i|-|%o|\n\n", &str, c, str, j, i, j);
	ft_printf("ft_printf prints |%p|-|%c|-|%s|-|%%|-|%x|-|%+i|-|%o|\n\n", &str, c, str, j, i, j);


	return (0);
}