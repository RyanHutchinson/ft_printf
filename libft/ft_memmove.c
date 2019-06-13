/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:32:38 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/23 09:59:13 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;
	size_t			i;

	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	i = n;
	if (tmpsrc == NULL && tmpdest == NULL)
		return (NULL);
	if (tmpsrc < tmpdest)
		while (i--)
		{
			tmpdest[i] = tmpsrc[i];
		}
	else
		dest = ft_memcpy(tmpdest, tmpsrc, n);
	return (dest);
}
