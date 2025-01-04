/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:16:28 by swenn             #+#    #+#             */
/*   Updated: 2025/01/04 13:25:56 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	execute_commands(t_nb_cmd nb_cmd, char **argv, char **envp,
		int **pipefds)
{
	int		j;
	t_cmd	cmd;

	j = 0;
	while (j < nb_cmd.num_cmds - 1)
	{
		close(pipefds[j][0]);
		close(pipefds[j][1]);
		j++;
	}
	cmd.cmd_args = ft_split(argv[nb_cmd.current_index + 2], ' ');
	push(cmd.cmd_args, 1);
	cmd.cmd = pipex_cmd_args(cmd.cmd_args[0], envp);
	if (!cmd.cmd)
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	execve(cmd.cmd, cmd.cmd_args, envp);
	perror("execve failed");
}

void	execute_pipeline(t_env env, int argc)
{
	int			**pipefds;
	pid_t		*pids;
	t_nb_cmd	nb_cmd;

	nb_cmd.num_cmds = argc - 3;
	nb_cmd.argc = argc;
	pipefds = init_pipes_and_pids(&pids, nb_cmd.num_cmds);
	create_processes(env, nb_cmd, pipefds, pids);
	cleanup_resources(pipefds, pids, nb_cmd.num_cmds);
}
