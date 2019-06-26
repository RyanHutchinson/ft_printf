/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/26 10:41:05 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "stdarg.h"

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
	int		type;
}typedef	t_format;

t_format	*ft_newformat();
int			ft_printf(const char *fmt, ...);
