/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:48:25 by jlorette          #+#    #+#             */
/*   Updated: 2024/12/23 00:08:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <unistd.h>
#include <sys/wait.h>

void	setup_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		error_message(1);
}

static void	execute_command(char *cmd, char **cmd_args, char **envp,
	int in_fd, int out_fd)
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	execve(cmd, cmd_args, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	first_child_process(char **argv, char **envp, int pipefd[2])
{
	int		infile;
	char	*cmd;
	char	**cmd_args;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_message(NO_FILES);
	cmd_args = ft_split(argv[2], ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd = pipex_cmd_args(cmd_args[0], envp);
	if (!cmd)
		error_message(NO_COMMAND_FOUND);
	close(pipefd[0]);
	execute_command(cmd, cmd_args, envp, infile, pipefd[1]);
}

void	second_child_process(char **argv, char **envp, int pipefd[2])
{
	int		outfile;
	char	*cmd;
	char	**cmd_args;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile == -1)
		error_message(FAILED_FILES_CREATION);
	cmd_args = ft_split(argv[3], ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd = pipex_cmd_args(cmd_args[0], envp);
	if (!cmd)
		error_message(NO_COMMAND_FOUND);
	close(pipefd[1]);
	execute_command(cmd, cmd_args, envp, pipefd[0], outfile);
}

void	wait_for_children(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
