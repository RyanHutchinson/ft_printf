/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/27 12:42:07 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int index, size_t n)
{
	char *new;

	if (str == NULL || !(new = ft_strnew(n)))
		return (NULL);
	return (ft_strncpy(new, &str[index], n));
}
