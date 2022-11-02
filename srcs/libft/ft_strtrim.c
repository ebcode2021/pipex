/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:08 by eunson            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:00 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*return_char;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	return_char = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!return_char)
		return (0);
	ft_strlcpy(return_char, s1 + start, end - start + 2);
	return (return_char);
}
