/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:12:41 by eunson            #+#    #+#             */
/*   Updated: 2022/07/24 18:46:33 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*return_list;

	return_list = (t_list *)malloc(sizeof(t_list));
	if (!return_list)
		return (0);
	return_list->content = content;
	return_list->next = 0;
	return (return_list);
}
