/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/18 16:04:11 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <fcntl.h>
#include <pipex.h>
#include <unistd.h>
#include <sys/wait.h>

// < file1 cm1 | cm2 > file2

int	main(int argc, char **argv, char **envp)
{
	char	*cmd1;
	char	**true_command;
	//int		pipefd[2];
	int infile;

	if (argc != 5)
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_message(NO_FILES);
	dup2(infile, STDOUT_FILENO);
	true_command = ft_split(argv[2], ' ');
	if (!true_command)
		exit(EXIT_FAILURE);
	push(true_command, 1);
	cmd1 = pipex_cmd_args(true_command[0], envp);
	if (!cmd1)
		error_message(NO_COMMAND_FOUND);
	int fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		error_message(FAILED_FILES_CREATION);
	dup2(fd, STDOUT_FILENO);
	execve(cmd1, true_command, NULL);
	perror("execve failed");
	close(infile);
	return (0);
}
