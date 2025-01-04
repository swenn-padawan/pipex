/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:43:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 14:20:16 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <pipex.h>

typedef struct s_env
{
	char	**argv;
	char	**envp;
}			t_env;

typedef struct s_nb_cmd
{
	int		argc;
	int		num_cmds;
	int		current_index;
}			t_nb_cmd;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

t_list		*ft_list_init(int argc, char **argv);
int			get_outfile(t_list *lst);
void		execute_pipeline(t_env env, int argc);
int			**init_pipes_and_pids(pid_t **pids, int num_cmds);
void		create_processes(t_env env, t_nb_cmd nb_cmd, int **pipefds,
				pid_t *pids);
void		cleanup_resources(int **pipefds, pid_t *pids, int num_cmds);
void		handle_redirection(t_env env, t_nb_cmd nb_cmd, int **pipefds);
void		execute_commands(t_nb_cmd nb_cmd, char **argv, char **envp,
				int **pipefds);

#endif
