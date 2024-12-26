/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:51 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/26 15:52:08 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/Libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum		e_error
{
	TOO_FEW_ARGS = 1,
	NO_PATH_FOUND,
	NO_PERMS,
	NO_FILES,
	NO_COMMAND_FOUND,
	FAILED_FILES_CREATION
};

typedef struct s_cmd
{
	char	*cmd;
	char	**cmd_args;
}			t_cmd;

//PARSING
char		*pipex_cmd_args(char *cmd, char **envp);

//ERROR
void		error_message(int error);

//PROCESS
void		setup_pipe(int pipefd[2]);
void		first_child_process(char **argv, char **envp, int pipefd[2]);
void		second_child_process(char **argv, char **envp, int pipefd[2]);
void		wait_for_children(pid_t pid1, pid_t pid2);

#endif
