/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:52 by eunson            #+#    #+#             */
/*   Updated: 2022/07/24 20:19:08 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_lst;

	if (!lst || !f)
		return ;
	tmp_lst = lst;
	while (tmp_lst)
	{
		f(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
	return ;
}
