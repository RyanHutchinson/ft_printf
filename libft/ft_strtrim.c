/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:47:23 by rhutchin          #+#    #+#             */
/*   Updated: 2019/05/27 08:33:34 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	int		start;
	int		end;
	int		len;
	char	*new;

	start = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (ft_strnew(1));
	end = len - 1;
	while (ft_iswhitespace(str[start]) == 1 && str[start] != '\0')
		start++;
	while (ft_iswhitespace(str[end]) == 1 && end >= start)
		end--;
	len = end - start + 1;
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new, &str[start], len);
	return (new);
}
