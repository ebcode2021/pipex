/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:16:43 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 16:38:59 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_find(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack++ != *needle++)
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	needle_len;

	index = 0;
	needle_len = ft_strlen(needle);
	if (!needle || needle_len == 0)
		return ((char *)haystack);
	while (*haystack && (index + needle_len) <= len)
	{
		if (is_find(haystack, needle) == 1)
			return ((char *)haystack);
		haystack++;
		index++;
	}
	return (0);
}
