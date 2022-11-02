/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:20:25 by eunson            #+#    #+#             */
/*   Updated: 2022/07/24 20:44:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*new_lst;

	if (!lst || !f)
		return (0);
	res_lst = 0;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&res_lst, del);
			return (0);
		}
		ft_lstadd_back(&res_lst, new_lst);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (res_lst);
}
