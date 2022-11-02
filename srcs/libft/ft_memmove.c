/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:16:13 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 15:24:18 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cp_dst;
	const unsigned char	*cp_src;

	if (!dst && !src)
		return (0);
	cp_dst = (unsigned char *)dst;
	cp_src = (const unsigned char *)src;
	if (cp_dst <= cp_src)
	{
		while (len--)
			*cp_dst++ = *cp_src++;
	}
	else
	{
		while (len--)
			cp_dst[len] = cp_src[len];
	}
	return (dst);
}
