/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:06:17 by eunson            #+#    #+#             */
/*   Updated: 2022/11/02 12:55:30 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 여기다가 에러 관련 처리 전부 해버리고 ~
#include "pipex.h"

int	print_err(char *location, int alias)
{
	ft_putstr_fd("bash : ", 2);
	errno = alias;
	perror(location);
	exit (1);
}

void	cmd_not_found_err(char *argv)
{
	ft_putstr_fd("bash : ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (1);
}

void	is_fork_err(pid_t pid)
{
	if (pid == -1)
	{
		print_err("fork_error", ECHILD);
		exit(1);
	}
}

void	is_pipe_err(int fd)
{
	if (fd == -1)
	{
		print_err("pipe_error", EPIPE);
		exit(1);
	}
}

void	is_dup_err(int fd)
{
	if (fd == -1)
	{
		print_err("dup_error", EBADF);
		exit(1);
	}
}
