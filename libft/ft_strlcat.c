/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:39:53 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/27 14:12:47 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = ft_strlen((const char *)dest);
	k = j;
	if (j > n)
		k = n;
	k += ft_strlen(src);
	while (src[i] != '\0' && i + j < n - 1 && n > 0)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (k);
}
