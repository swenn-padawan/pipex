/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:48:25 by jlorette          #+#    #+#             */
/*   Updated: 2024/12/26 15:48:27 by swenn            ###   ########.fr       */
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

static void	execute_command(t_cmd cmd, char **envp,
	int in_fd, int out_fd)
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	execve(cmd.cmd, cmd.cmd_args, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	first_child_process(char **argv, char **envp, int pipefd[2])
{
	int		infile;
	t_cmd	cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_message(NO_FILES);
	cmd.cmd_args = ft_split(argv[2], ' ');
	if (!cmd.cmd_args)
		exit(EXIT_FAILURE);
	cmd.cmd = pipex_cmd_args(cmd.cmd_args[0], envp);
	if (!cmd.cmd)
		error_message(NO_COMMAND_FOUND);
	close(pipefd[0]);
	execute_command(cmd, envp, infile, pipefd[1]);
}

void	second_child_process(char **argv, char **envp, int pipefd[2])
{
	int		outfile;
	t_cmd	cmd;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile == -1)
		error_message(FAILED_FILES_CREATION);
	cmd.cmd_args = ft_split(argv[3], ' ');
	if (!cmd.cmd_args)
		exit(EXIT_FAILURE);
	cmd.cmd = pipex_cmd_args(cmd.cmd_args[0], envp);
	if (!cmd.cmd)
		error_message(NO_COMMAND_FOUND);
	close(pipefd[1]);
	execute_command(cmd, envp, pipefd[0], outfile);
}

void	wait_for_children(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
