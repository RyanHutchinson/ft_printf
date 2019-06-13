/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:30:10 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/27 08:29:56 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (-1);
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	else
		return (0);
}
