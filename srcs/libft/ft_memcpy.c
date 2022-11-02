/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:50:08 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 15:28:18 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cp_dst;
	const char	*cp_src;

	if (!dst && !src)
		return (0);
	cp_dst = dst;
	cp_src = src;
	while (n)
	{
		*cp_dst++ = *cp_src++;
		n--;
	}
	return (dst);
}
