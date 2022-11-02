/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:54:31 by eunson            #+#    #+#             */
/*   Updated: 2022/07/19 13:17:21 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	cnt_digit(long long long_n, int n)
{
	int	cnt;

	cnt = 1;
	while (long_n >= 10)
	{
		long_n /= 10;
		cnt++;
	}
	if (n < 0)
		cnt++;
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*tmp;
	int			cnt;
	long long	long_n;

	long_n = (long long)n;
	if (long_n < 0)
		long_n *= -1;
	cnt = cnt_digit(long_n, n);
	tmp = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!tmp)
		return (0);
	if (n < 0)
		tmp[0] = '-';
	if (n == 0)
		tmp[0] = '0';
	tmp[cnt] = 0;
	while (long_n)
	{
		cnt--;
		tmp[cnt] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (tmp);
}
