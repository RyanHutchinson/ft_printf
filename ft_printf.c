/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:54:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/13 15:46:49 by rhutchin         ###   ########.fr       */
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
			int	tmp;

			tmp = va_arg(ap, int);
			// <--------------------------------------------------------------- I need to do some junk here to make octal do things. Hex kinda just works but I have no idea....
			ft_putnbr(tmp);
		}
	if (fmt[1] == 'u')
		ft_putnbr(va_arg(ap, unsigned int));//<-------------------------------- I am not sure of wtf should happen here.... it works but does not !work when a !unsigned-int is passed.
//	if (fmt[1] == 'f' || fmt[1] == 'F')
//		----------------------------------------------------------------------- double in normal (fixed-point) notation. f and F only differs in how the strings for an infinite number
//																				or NaN are printed (inf, infinity and nan for f; INF, INFINITY and NAN for F). 
//	if (fmt[1] == 'e' || fmt[1] == 'E')
//		----------------------------------------------------------------------- double value in standard form ([-]d.ddd e[+/-]ddd). An E conversion uses the letter E (rather than e) to
//																				introduce the exponent. The exponent always contains at least two digits; if the value is zero, the
//																				exponent is 00. In Windows, the exponent contains three digits by default, e.g. 1.5e002, but this can be
//																				altered by Microsoft-specific _set_output_format function. 
//	if (fmt[1] == 'g' || fmt[1] == 'G')
//		----------------------------------------------------------------------- double in either normal or exponential notation, whichever is more appropriate for its magnitude. g uses
//																				lower-case letters, G uses upper-case letters. This type differs slightly from fixed-point notation in that
//																				insignificant zeroes to the right of the decimal point are not included. Also, the decimal point is not
//																				included on whole numbers. 
//	if (fmt[1] == 'x' || fmt[1] == 'X')
//		----------------------------------------------------------------------- unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case.
//																				!!!!!!!!!!!!!WRITE ATOIBASE!!!!!!!!!!!!!!!
//	if (fmt[1] == 'o')
//		----------------------------------------------------------------------- unsigned int in octal.
//																				!!!!!!!!!!!!!WRITE ATOIBASE!!!!!!!!!!!!!!!
	if (fmt[1] == 's')
		ft_putstr(va_arg(ap, char *));
	if (fmt[1] == 'c')
		ft_putchar(va_arg(ap, int));
	if (fmt[1] == 'p')	//----------------------------------------------------- this does not work.
		{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base((long)va_arg(ap, void *), 16));
		}
//		----------------------------------------------------------------------- void * (pointer to void) in an implementation-defined format.
//	if (fmt[1] == 'a' || fmt[1] == 'A')
//		----------------------------------------------------------------------- double in hexadecimal notation, starting with 0x or 0X. a uses lower-case letters, A uses upper-case
//																				letters.[4][5] (C++11 iostreams have a hexfloat that works the same). 
//	if (fmt[1] == 'n')
//		----------------------------------------------------------------------- This currently works but is down in the 'main' ft_printf function sooooo... figure that out.
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
	char 	c = 'A';
	char	*i = "things";
	int		n;

	printf("printf prints the param as --->%p<--->%c<--->%%<---\n\n", &i, c);
	ft_printf("ft_printf currently prints --->%p<--%n->%c<--->%%<---", &i, &n, c);
	ft_printf("\n%d\n", n);
	return (0);
}