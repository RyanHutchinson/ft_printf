/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:54:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 11:45:21 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./incl/ft_printf.h"

static int	paramchecker(const char *fmt, va_list ap, t_format *format)
{
	int	i;

	i = 0;
	i += checkflags(i, fmt, format); //---------------------------------------- Check formatting flags.
	i += checkwidth(i, fmt, format); //---------------------------------------- Check minimum width.
	i += checkprecision(i, fmt, format); //------------------------------------ Check the precision.
	i += checklength(i, fmt, format); //--------------------------------------- Check length.
	i += checktype(i, fmt, format, ap); //------------------------------------- Check Type.
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
			format = newformat();
			i += paramchecker(&fmt[i], ap, format);
		}
		delformat(format); //----------------------------------------------- Write this junk
		i++;
	}
	va_end(ap);
	return (0);
}