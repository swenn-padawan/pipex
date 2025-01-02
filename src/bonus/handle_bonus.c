/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:15:47 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/02 13:18:44 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	setup_first_command(int i, char **argv, int **pipefds)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("open infile");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(pipefds[i][1], STDOUT_FILENO);
}

void	setup_last_command(int i, int argc, int **pipefds, char **argv)
{
	int	outfile;

	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile == -1)
	{
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	dup2(pipefds[i - 1][0], STDIN_FILENO);
	close(pipefds[i - 1][0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	setup_intermediate_command(int i, int **pipefds)
{
	dup2(pipefds[i - 1][0], STDIN_FILENO);
	dup2(pipefds[i][1], STDOUT_FILENO);
}

void	handle_redirection(int i, int num_cmds, char **argv, int **pipefds,
		int argc)
{
	if (i == 0)
		setup_first_command(i, argv, pipefds);
	else if (i == num_cmds - 1)
		setup_last_command(i, argc, pipefds, argv);
	else
		setup_intermediate_command(i, pipefds);
}
