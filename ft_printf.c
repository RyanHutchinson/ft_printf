/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:54:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 09:51:40 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//you need to do the stuff to make wide chars do things.

#include <stdio.h>
#include "./incl/ft_printf.h"
/*
int	isconversion(const char fmt)
{
	ft_strchr("%idDuUxX", fmt)
	return(fmt == '%' || fmt == 'i' || fmt == 'd' || fmt == 'D' || fmt == 'u' || fmt == 'U' || fmt == 'x' || fmt == 'X' || fmt == 'o' || fmt == 'O' || fmt == 's' || fmt == 'c' || fmt == 'p');
}
*/
int	checkflags(int i, const char *fmt, t_format *format)
{
}
int	checkwidth(int i, const char *fmt, t_format *format)
{
}
int	checkprecision(int i, const char *fmt, t_format *format)
{
}
int	checklength(int i, const char *fmt, t_format *format)
{
}



int	checktype(const char *fmt, va_list ap, int i, t_format *format)
{
	if (fmt[i] == '%')
		ft_putchar('%');
	if (fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i')
	{
		if(fmt[2] == '0' && fmt[3] != 'x')
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
	i += checkflags(i, fmt, format); //---------------------------------------- Check formatting flags.
	i += checkwidth(i, fmt, format); //---------------------------------------- Check minimum width.
	i += checkprecision(i, fmt, format); //------------------------------------ Check the precision.
	i += checklength(i, fmt, format); //--------------------------------------- Check length.
	i += checktype(fmt, ap, i, format); //------------------------------------- Check Type.
	printer(i, format);
	return(i);
}

int	ft_printf(const char *fmt, ...)
{
	int			i;
	va_list		ap;
	t_format	*format;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		
		if (fmt[i] != '%')
			ft_putchar(fmt[i]);
		if (fmt[i] == '%')
		{
			format = ft_newformat();
			i += paramchecker(&fmt[i], ap, format);
		}
		ft_delformat(format); //----------------------------------------------- Write this junk
		i++;
	}
	va_end(ap);
	return (0);
}