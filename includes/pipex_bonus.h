/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:43:10 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/29 11:44:04 by swenn            ###   ########.fr       */
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
void execute_pipeline(char **argv, int argc, char **envp);

#endif
