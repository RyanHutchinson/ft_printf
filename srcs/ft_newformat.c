/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:36:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 11:04:39 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

t_format	*ft_newformat()
{
	t_format *new;

	if(!(new = malloc(sizeof(t_format))))
		return (NULL);
	new->padding = 0;
	new->sign = NULL;
	new->space = ' ';
	new->zero = 0;
	new->hash = NULL;
	new->width = 0;
	new->precision = 0;
	new->length = NULL;
	new->type = 0;

	return(new);
}