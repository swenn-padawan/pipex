/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:16:28 by swenn             #+#    #+#             */
/*   Updated: 2024/12/29 11:51:27 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>


void execute_pipeline(char **argv, int argc, char **envp)
{
    int **pipefds;
    pid_t *pids;
    int num_cmds = argc - 3;
    int i;

    pipefds = malloc((num_cmds - 1) * sizeof(int *));
    for (i = 0; i < num_cmds - 1; i++)
        pipefds[i] = malloc(2 * sizeof(int));
    pids = malloc(num_cmds * sizeof(pid_t));
    for (i = 0; i < num_cmds - 1; i++)
    {
        if (pipe(pipefds[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < num_cmds; i++)
    {
        pids[i] = fork();
        if (pids[i] == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0)
        {
            if (i == 0)
            {
                int infile = open(argv[1], O_RDONLY);
                if (infile == -1)
                {
                    perror("open infile");
                    exit(EXIT_FAILURE);
                }
                dup2(infile, STDIN_FILENO);
                close(infile);
                dup2(pipefds[i][1], STDOUT_FILENO);
            }
            else if (i == num_cmds - 1)
            {
                int outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
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
            else
            {
                dup2(pipefds[i - 1][0], STDIN_FILENO);
                dup2(pipefds[i][1], STDOUT_FILENO);
            }
            for (int j = 0; j < num_cmds - 1; j++)
            {
                close(pipefds[j][0]);
                close(pipefds[j][1]);
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
    }
    for (i = 0; i < num_cmds - 1; i++)
    {
        close(pipefds[i][0]);
        close(pipefds[i][1]);
    }
    for (i = 0; i < num_cmds; i++)
        waitpid(pids[i], NULL, 0);
    for (i = 0; i < num_cmds - 1; i++)
        free(pipefds[i]);
    free(pipefds);
    free(pids);
}

