/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:25:50 by eunson            #+#    #+#             */
/*   Updated: 2022/10/20 20:04:06 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_node(t_nodes **node)
{
	t_nodes	*free_node;

	free_node = *node;
	*node = (*node)->next;
	free(free_node);
}

static int	ft_return_len(int fd, t_nodes *node)
{
	int		start_idx;
	int		total_len;

	start_idx = node -> start_idx;
	total_len = 0;
	while (node)
	{
		total_len++;
		if (node -> content[start_idx++] == '\n')
			break ;
		if (start_idx == node -> end_idx)
		{
			start_idx = 0;
			node = node -> next;
			while (node && node -> fd != fd)
				node = node -> next;
		}
	}
	return (total_len);
}

static char	*ft_read_line(int fd, t_nodes **start_node)
{
	int			idx;
	int			return_len;
	char		*return_line;

	idx = 0;
	return_len = ft_return_len(fd, *start_node);
	return_line = (char *)malloc(sizeof(char) * (return_len + 1));
	while (idx < return_len)
	{
		return_line[idx++] = (*start_node)->content[(*start_node)->start_idx++];
		if ((*start_node)->start_idx == (*start_node)->end_idx)
		{
			ft_free_node(start_node);
			while (*start_node && (*start_node)->fd != fd)
				start_node = &((*start_node)->next);
		}
	}
	return_line[return_len] = '\0';
	return (return_line);
}

static t_nodes	*ft_make_node(int fd, t_nodes **start_node)
{
	int			content_len;
	char		content[BUFFER_SIZE];
	t_nodes		*new_node;

	content_len = read(fd, content, BUFFER_SIZE);
	if (content_len < 1)
		return (NULL);
	new_node = (t_nodes *)malloc(sizeof(t_nodes));
	if (!new_node)
		return (NULL);
	ft_insert_inform(&new_node, fd, content, content_len);
	if (!gnl_strchar(content, '\n', content_len))
		ft_make_node(fd, &new_node);
	return (ft_nodes_add_back(start_node, new_node));
}

char	*get_next_line(int fd)
{
	static t_nodes	*storage;
	t_nodes			**start_node;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	start_node = &storage;
	while (*start_node && (*start_node)->fd != fd)
		start_node = &((*start_node)->next);
	if (!*start_node || !gnl_strchar((*start_node)->content
			+ (*start_node)->start_idx, '\n',
			(*start_node)->end_idx - (*start_node)->start_idx))
		ft_make_node(fd, start_node);
	if (!*start_node)
		return (NULL);
	return (ft_read_line(fd, start_node));
}
