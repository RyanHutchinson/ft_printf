/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isconversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:44:06 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 11:45:00 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	isconversion(const char fmt)
{
	//ft_strchr("%idDuUxX", fmt)
	return(fmt == '%' || fmt == 'i' || fmt == 'd' || fmt == 'D' || fmt == 'u' \
    || fmt == 'U' || fmt == 'x' || fmt == 'X' || fmt == 'o' || fmt == 'O' || \
    fmt == 's' || fmt == 'c' || fmt == 'p');
}