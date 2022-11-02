/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:41:24 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 15:50:22 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_s;
	size_t	malloc_len;
	size_t	index;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	malloc_len = ft_strlen(s);
	if (malloc_len > len)
		malloc_len = len;
	return_s = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (!return_s)
		return (0);
	index = 0;
	while (s[start + index] && index < len)
	{
		return_s[index] = s[start + index];
		index++;
	}
	return_s[index] = 0;
	return (return_s);
}
