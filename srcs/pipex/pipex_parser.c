/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:54:12 by eunson            #+#    #+#             */
/*   Updated: 2022/10/28 14:20:02 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd_name, t_inform *inform)
{
	char	**path_lists;
	char	*cmd_path;

	path_lists = get_path_in_envp(inform->envp);
	while (*path_lists)
	{
		cmd_path = (char *)malloc(ft_strlen(*path_lists) + 1);
		cmd_path = ft_strjoin(*path_lists, "/");
		cmd_path = ft_strjoin(cmd_path, cmd_name);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		path_lists++;
	}
	return (0);
}

char	**get_path_in_envp(char *envp[])
{
	char	*path;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}
