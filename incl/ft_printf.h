/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 12:10:33 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

struct		s_format	
{
	int		padding;
	char	sign;
	char	space;
	int		zero;
	char	hash;
	int		width;
	int		precision;
	char	length;
	char	type;
	void*	value;
}typedef	t_format;

int			ft_printf(const char *fmt, ...);

t_format	*newformat();
int			checkflags(int i, const char *fmt, t_format *format);
int			checkwidth(int i, const char *fmt, t_format *format);
int			checkprecision(int i, const char *fmt, t_format *format);
int			checklength(int i, const char *fmt, t_format *format);
int			checktype(int i, const char *fmt, t_format *format, va_list ap);