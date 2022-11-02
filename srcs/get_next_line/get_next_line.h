/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:25:52 by eunson            #+#    #+#             */
/*   Updated: 2022/10/20 20:04:14 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	char			content[BUFFER_SIZE + 1];
	int				fd;
	int				start_idx;
	int				end_idx;
	struct s_node	*next;
}	t_nodes;

// get_next_line.c file
char	*get_next_line(int fd);

// get_next_line_utils.c file
int		gnl_strchar(char *s, char c, int len);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
t_nodes	*ft_nodes_add_back(t_nodes **start_node, t_nodes *new_node);
void	ft_insert_inform(t_nodes **new_node, int fd, char *content, int len);

#endif