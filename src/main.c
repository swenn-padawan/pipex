/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/26 15:43:34 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	setup_pipe(pipefd);
	pid1 = fork();
	if (pid1 == -1)
		error_message(1);
	if (pid1 == 0)
		first_child_process(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		error_message(1);
	if (pid2 == 0)
		second_child_process(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	wait_for_children(pid1, pid2);
	return (0);
}
