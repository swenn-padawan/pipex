/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:16:28 by swenn             #+#    #+#             */
/*   Updated: 2025/01/04 11:31:54 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void execute_commands(int i, char **argv, char **envp, int **pipefds, int num_cmds)
{
	int	j;

	j = 0;
    while (j < num_cmds - 1)
    {
        close(pipefds[j][0]);
        close(pipefds[j][1]);
		j++;
    }
    t_cmd cmd;
    cmd.cmd_args = ft_split(argv[i + 2], ' ');
    cmd.cmd = pipex_cmd_args(cmd.cmd_args[0], envp);
    if (!cmd.cmd)
    {
        perror("command not found");
        exit(EXIT_FAILURE);
    }
    execve(cmd.cmd, cmd.cmd_args, envp);
    perror("execve failed");
    exit(EXIT_FAILURE);
}

void execute_pipeline(char **argv, int argc, char **envp)
{
    int **pipefds;
    pid_t *pids;
    int num_cmds = argc - 3;

    init_pipes_and_pids(&pipefds, &pids, num_cmds);
    create_processes(num_cmds, argv, pipefds, pids, envp, argc);
    cleanup_resources(pipefds, pids, num_cmds);
}
