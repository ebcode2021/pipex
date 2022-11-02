/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:22:24 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 11:34:22 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			index;
	size_t			src_len;

	index = 0;
	src_len = ft_strlen(src);
	while (src[index] && ((index + 1) < dstsize))
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize)
		dst[index] = 0;
	return (src_len);
}
