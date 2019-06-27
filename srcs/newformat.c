/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:36:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/27 13:03:14 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

t_format	*newformat()
{
	t_format *new;

	if(!(new = malloc(sizeof(t_format))))
		return (NULL);
	new->padding = NULL;
	new->sign = NULL;
	new->space = NULL;
	new->zero = NULL;
	new->hash = NULL;
	new->width = NULL;
	new->precision = NULL;
	new->length = NULL;
	new->type = NULL;
	new->value = NULL;

	return(new);
}