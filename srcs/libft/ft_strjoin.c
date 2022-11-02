/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:55:27 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 16:13:17 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		prefix_len;
	int		suffix_len;
	int		index;
	char	*return_char;

	if (!s1 || !s2)
		return (0);
	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	return_char = (char *)malloc(sizeof(char) * (prefix_len + suffix_len + 1));
	if (!return_char)
		return (0);
	index = -1;
	while (s1[++index])
		return_char[index] = s1[index];
	index = -1;
	while (s2[++index])
		return_char[prefix_len + index] = s2[index];
	return_char[prefix_len + index] = 0;
	return (return_char);
}
