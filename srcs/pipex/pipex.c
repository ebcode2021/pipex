/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:01:59 by eunson            #+#    #+#             */
/*   Updated: 2022/11/27 10:53:55 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	pipe_n_fork(t_pipe *iter_pipe)
{
	int	pid;

	is_pipe_err(pipe(iter_pipe->fd));
	pid = fork();
	is_fork_err(pid);
	return (pid);
}

void	parents_proc(t_inform *inform, int *status)
{
	pid_t	pid;
	t_pipe	iter_pipe;

	iter_pipe.prev_fd = -1;
	if (inform->here_doc)
		here_doc_func(inform->argv[2]);
	while (inform->cmd_idx < inform->argc - 1)
	{
		pid = pipe_n_fork(&iter_pipe);
		if (pid == 0)
		{
			child_proc(inform, &iter_pipe);
			break ;
		}
		close(iter_pipe.prev_fd);
		iter_pipe.prev_fd = iter_pipe.fd[READ];
		inform->cmd_idx++;
		close(iter_pipe.fd[WRITE]);
	}
	close(iter_pipe.fd[READ]);
	waitpid(pid, status, 0);
}

void	change_io_fd(t_inform *inform, int io)
{
	int	change_fd;

	if (io == FIRST)
	{
		change_fd = open(inform->argv[1], O_RDONLY);
		if (change_fd == -1)
			print_err(inform->argv[1], errno);
		else
			is_dup_err(dup2(change_fd, STDIN_FILENO));
	}
	else
	{
		if (inform->here_doc)
			change_fd = open(inform->argv[inform->argc - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0666);
		else
			change_fd = open(inform->argv[inform->argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
		is_dup_err(dup2(change_fd, STDOUT_FILENO));
	}
	close(change_fd);
}

void	child_proc(t_inform *inform, t_pipe *iter_pipe)
{
	if (inform->here_doc && inform->cmd_idx == 3)
		is_dup_err(dup2(iter_pipe->fd[WRITE], STDOUT_FILENO));
	else if (inform->cmd_idx == 2)
	{
		change_io_fd(inform, FIRST);
		is_dup_err(dup2(iter_pipe->fd[WRITE], STDOUT_FILENO));
	}
	else if (inform->cmd_idx == inform -> argc - 2)
	{
		is_dup_err(dup2(iter_pipe->prev_fd, STDIN_FILENO));
		change_io_fd(inform, LAST);
	}
	else
	{
		is_dup_err(dup2(iter_pipe->prev_fd, STDIN_FILENO));
		is_dup_err(dup2(iter_pipe->fd[WRITE], STDOUT_FILENO));
	}
	close(iter_pipe->fd[READ]);
	close(iter_pipe->fd[WRITE]);
	close(iter_pipe->prev_fd);
	cmd_exe(inform);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_inform	inform;
	int			status;

	if (argc == 1)
		exit (EXIT_FAILURE);
	init_inform(argc, argv, envp, &inform);
	if ((!inform.here_doc && argc < 5) || (inform.here_doc && argc < 6))
		return (print_err("subject rule check : ", EIO));
	parents_proc(&inform, &status);
	while (inform.total_cmd--)
		waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
