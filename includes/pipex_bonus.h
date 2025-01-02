/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:43:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/02 13:11:31 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <pipex.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

t_list		*ft_list_init(int argc, char **argv);
int			get_outfile(t_list *lst);
void		execute_pipeline(char **argv, int argc, char **envp);
void		init_pipes_and_pids(int ***pipefds, pid_t **pids, int num_cmds);
void		create_processes(int num_cmds, char **argv, int **pipefds, pid_t *pids, char **envp, int argc);
void		cleanup_resources(int **pipefds, pid_t *pids, int num_cmds);
void handle_redirection(int i, int num_cmds, char **argv, int **pipefds, int argc);
void execute_commands(int i, char **argv, char **envp, int **pipefds, int num_cmds);


#endif
