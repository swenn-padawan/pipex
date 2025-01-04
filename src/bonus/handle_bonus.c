/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:15:47 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 12:10:22 by swenn            ###   ########.fr       */
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

static void	setup_last_command(t_nb_cmd nb_cmd, int **pipefds, char **argv)
{
	int	outfile;

	outfile = open(argv[nb_cmd.argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile == -1)
	{
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	dup2(pipefds[nb_cmd.current_index - 1][0], STDIN_FILENO);
	close(pipefds[nb_cmd.current_index - 1][0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	setup_intermediate_command(int i, int **pipefds)
{
	dup2(pipefds[i - 1][0], STDIN_FILENO);
	dup2(pipefds[i][1], STDOUT_FILENO);
}

void	handle_redirection(t_env env, t_nb_cmd nb_cmd, int **pipefds)
{
	if (nb_cmd.current_index == 0)
		setup_first_command(nb_cmd.current_index, env.argv, pipefds);
	else if (nb_cmd.current_index == nb_cmd.num_cmds - 1)
		setup_last_command(nb_cmd, pipefds, env.argv);
	else
		setup_intermediate_command(nb_cmd.current_index, pipefds);
}
