/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:16:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/29 11:33:30 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/Libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

enum		e_error
{
	TOO_FEW_ARGS = 1,
	NO_PATH_FOUND,
	NO_PERMS,
	NO_FILES,
	NO_COMMAND_FOUND,
	FAILED_FILES_CREATION,
	FORK_FAILED
};

typedef struct s_cmd
{
	char	*cmd;
	char	**cmd_args;
}			t_cmd;

// PARSING
char		*pipex_cmd_args(char *cmd, char **envp);

// ERROR
void		error_message(int error);

// PROCESS
void	setup_pipe(int pipefd[2]);
void	execute_command(t_cmd cmd, char **envp, int in_fd, int out_fd);
void	first_child_process(char **argv, char **envp, int pipefd[2]);
void	second_child_process(int argc, char **argv, char **envp,
				int pipefd[2]);
void	wait_for_children(pid_t pid1, pid_t pid2);

#endif
