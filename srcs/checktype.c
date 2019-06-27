/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:34:40 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 14:45:19 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	checktype(int i, const char *fmt, t_format *format, va_list ap)
{
	if (fmt[i++] == '%')
	{
		format->type = "char";
		format->value = '%';
	}
	else if (fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i')
	{
		if(fmt[i + 1] == '0' && fmt[i + 2] != 'x')
		{
			format->type = "octal";
			format->value = ft_itoa_base(va_arg(ap, int), 8);
		}
		else
		//	format->
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