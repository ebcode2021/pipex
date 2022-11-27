/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:03:04 by eunson            #+#    #+#             */
/*   Updated: 2022/11/27 09:32:30 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft.h"
# include "get_next_line.h"

# define READ 0
# define WRITE 1

# define FIRST 1
# define LAST 0

typedef struct s_inform
{
	int		argc;
	int		here_doc;
	int		cmd_idx;
	int		total_cmd;
	char	**argv;
	char	**envp;
}	t_inform;

typedef struct s_pipe
{
	int		fd[2];
	int		prev_fd;
}	t_pipe;

// pipex.c
void	parents_proc(t_inform *inform, int *status);
void	child_proc(t_inform *inform, t_pipe *iter_pipe);
void	change_io_fd(t_inform *inform, int io);
void	cmd_exe(t_inform *inform);
int		main(int argc, char **argv, char **envp);

// pipex_utils.c
void	init_inform(int argc, char *argv[], char *envp[], t_inform *inform);
int		here_doc_func(char *delim);

// pipex_error.c
int		print_err(char *location, int alias);
void	cmd_not_found_err(char *argv);
void	is_dup_err(int fd);
void	is_fork_err(pid_t pid);
void	is_pipe_err(int fd);

// pipex_parser.c
char	*get_cmd_path(char *cmd_name, t_inform *inform);
char	**get_path_in_envp(char *envp[]);

#endif
