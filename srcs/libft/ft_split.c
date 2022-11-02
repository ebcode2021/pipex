/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:40:25 by eunson            #+#    #+#             */
/*   Updated: 2022/07/24 15:49:31 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	cnt_total_word(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx])
			cnt++;
		while (s[idx] && s[idx] != c)
			idx++;
	}
	return (cnt);
}

static char	**ft_free(char **str, int idx)
{
	while (idx)
		free (str[idx--]);
	free (str);
	return (0);
}

void	check_point(char const *s, int *idx, char c, int *check)
{
	while (s[*idx] && s[*idx] == c)
		(*idx)++;
	if (s[*idx])
		*check = *idx;
	while (s[*idx] && s[*idx] != c)
		(*idx)++;
}

char	**ft_split(char const *s, char c)
{
	char	**return_char;
	int		idx;
	int		re_idx;
	int		check;
	int		total_word;

	idx = 0;
	re_idx = 0;
	if (!s)
		return (0);
	total_word = cnt_total_word(s, c);
	return_char = (char **)malloc(sizeof(char *) * (total_word + 1));
	if (!return_char)
		return (0);
	while (total_word--)
	{
		check_point(s, &idx, c, &check);
		return_char[re_idx] = malloc(sizeof(char) * (idx - check + 1));
		if (!return_char[re_idx])
			return (ft_free(return_char, idx - 1));
		ft_strlcpy(return_char[re_idx++], &s[check], idx - check + 1);
	}
	return_char[re_idx] = 0;
	return (return_char);
}
