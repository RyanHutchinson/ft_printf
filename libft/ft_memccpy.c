/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 08:14:39 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/22 14:39:45 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmpdest[i] = tmpsrc[i];
		if (tmpsrc[i] == ch)
			return ((void *)tmpdest + i + 1);
		i++;
	}
	return (NULL);
}
