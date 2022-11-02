/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:18:47 by eunson            #+#    #+#             */
/*   Updated: 2022/07/27 10:25:23 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	if (!lst || !del)
		return ;
	tmp_lst = *lst;
	while (*lst)
	{
		tmp_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_lst;
	}
}
