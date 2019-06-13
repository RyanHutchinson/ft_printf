/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:31:31 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/29 11:07:54 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replacechr(char **str, char f, char r)
{
	char	*ptr;

	if ((ptr = ft_strchr(*str, f)) == NULL)
		return (NULL);
	ptr = &r;
	return (ptr);
}
