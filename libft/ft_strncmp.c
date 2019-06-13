/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:12:39 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/29 08:52:30 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	int			diff;

	i = 0;
	if (n == 0)
		return (0);
	diff = (unsigned char)str1[i] - (unsigned char)str2[i];
	while ((diff == 0 && i < n - 1) && (str1[i] != '\0' && str2[i] != '\0'))
	{
		i++;
		diff = (unsigned char)str1[i] - (unsigned char)str2[i];
	}
	return (diff);
}
