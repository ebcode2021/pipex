/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:45:33 by eunson            #+#    #+#             */
/*   Updated: 2022/07/25 12:12:23 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	index;
	char			*str;

	if (!(s && f))
		return (0);
	s_len = ft_strlen(s);
	index = 0;
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (0);
	while (index < s_len)
	{
		str[index] = f(index, *(s + index));
		index++;
	}
	str[index] = 0;
	return (str);
}
