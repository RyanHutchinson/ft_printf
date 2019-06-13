/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:24:18 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/22 15:30:01 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;
	int				diff;

	tmp1 = (unsigned char *)str1;
	tmp2 = (unsigned char *)str2;
	i = 0;
	diff = 0;
	while (diff == 0 && i < n)
	{
		diff = tmp1[i] - tmp2[i];
		i++;
	}
	return (diff);
}
