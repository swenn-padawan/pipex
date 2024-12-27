/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:16:29 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 13:56:44 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**check_args(int argc, char **envp)
{
	if (argc != 5)
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	return (envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	envp = check_args(argc, envp);
	setup_pipe(pipefd);
	pid1 = fork();
	if (pid1 == -1)
		error_message(FORK_FAILED);
	if (pid1 == 0)
		first_child_process(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		error_message(FORK_FAILED);
	if (pid2 == 0)
		second_child_process(argc, argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	wait_for_children(pid1, pid2);
	return (0);
}
