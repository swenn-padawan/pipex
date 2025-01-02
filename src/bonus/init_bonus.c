/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:38 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/02 13:06:25 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void init_pipes_and_pids(int ***pipefds, pid_t **pids, int num_cmds)
{
	int	i;

	i = 0;
    *pipefds = malloc((num_cmds - 1) * sizeof(int *));
    while (i < num_cmds - 1)
        (*pipefds)[i++] = malloc(2 * sizeof(int));
    *pids = malloc(num_cmds * sizeof(pid_t));
	i = 0;
    while (i < num_cmds - 1)
    {
        if (pipe((*pipefds)[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
		i++;
    }
}

void create_processes(int num_cmds, char **argv, int **pipefds, pid_t *pids, char **envp, int argc)
{
	int	i;

	i = 0;
    while (i < num_cmds)
    {
        pids[i] = fork();
        if (pids[i] == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0)
        {
            handle_redirection(i, num_cmds, argv, pipefds, argc);
            execute_commands(i, argv, envp, pipefds, num_cmds);
        }
		i++;
    }
}

