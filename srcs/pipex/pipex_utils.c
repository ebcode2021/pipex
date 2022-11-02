/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:08:11 by eunson            #+#    #+#             */
/*   Updated: 2022/11/02 13:45:01 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_inform(int argc, char *argv[], char *envp[], t_inform *inform)
{
	inform->argc = argc;
	inform->argv = argv;
	inform->envp = envp;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		inform->here_doc = 1;
		inform->cmd_idx = 3;
		inform->total_cmd = argc - 4;
	}
	else
	{
		inform->here_doc = 0;
		inform->cmd_idx = 2;
		inform->total_cmd = argc - 3;
	}
}

void	cmd_exe(t_inform *inform)
{
	char	**cmd_argv;
	char	*cmd_path;

	cmd_argv = ft_split(inform->argv[inform->cmd_idx], ' ');
	cmd_path = get_cmd_path(cmd_argv[0], inform);
	if (!cmd_path)
		cmd_not_found_err(cmd_argv[0]);
	else
		execve(cmd_path, cmd_argv, inform->envp);
	exit(1);
}

void	here_doc_func(char *delim)
{
	int		tmp_fd;
	char	*gnl_str;

	tmp_fd = open("tmp_file", O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (1)
	{
		write(1, " > ", 3);
		gnl_str = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(gnl_str, delim, ft_strlen(delim)) \
			&& (ft_strlen(delim) + 1) == ft_strlen(gnl_str))
			break ;
		ft_putstr_fd(gnl_str, tmp_fd);
		free(gnl_str);
	}
	is_dup_err(dup2(open("tmp_file", O_RDONLY), STDIN_FILENO));
	close(tmp_fd);
	unlink("tmp_file");
}
