/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:38 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 14:20:28 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	**init_pipes_and_pids(pid_t **pids, int num_cmds)
{
	int	**pipefds;
	int	i;

	i = 0;
	pipefds = malloc((num_cmds - 1) * sizeof(int *));
	while (i < num_cmds - 1)
		pipefds[i++] = malloc(2 * sizeof(int));
	*pids = malloc(num_cmds * sizeof(pid_t));
	push(*pids, 0);
	i = 0;
	while (i < num_cmds - 1)
	{
		if (pipe(pipefds[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipefds);
}

void	create_processes(t_env env, t_nb_cmd nb_cmd, int **pipefds, pid_t *pids)
{
	nb_cmd.current_index = 0;
	while (nb_cmd.current_index < nb_cmd.num_cmds)
	{
		pids[nb_cmd.current_index] = fork();
		if (pids[nb_cmd.current_index] == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pids[nb_cmd.current_index] == 0)
		{
			handle_redirection(env, nb_cmd, pipefds);
			execute_commands(nb_cmd, env.argv, env.envp, pipefds);
		}
		nb_cmd.current_index++;
	}
}
