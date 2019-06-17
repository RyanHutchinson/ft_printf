/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:36:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/17 15:38:57 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

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