/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:11:57 by eunson            #+#    #+#             */
/*   Updated: 2022/07/22 15:13:14 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		s_len;
	int		index;
	char	*tmp;

	s_len = ft_strlen(s1);
	index = 0;
	tmp = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!tmp)
		return (0);
	while (s1[index])
	{
		tmp[index] = s1[index];
		index++;
	}
	tmp[index] = 0;
	return (tmp);
}
