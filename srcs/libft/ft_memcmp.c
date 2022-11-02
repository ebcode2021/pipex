/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:26 by eunson            #+#    #+#             */
/*   Updated: 2022/07/15 12:22:50 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	index = 0;
	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (unsigned_s1[index] != unsigned_s2[index])
			return (unsigned_s1[index] - unsigned_s2[index]);
		index++;
	}
	return (0);
}
