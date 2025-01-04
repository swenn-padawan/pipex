/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:21:36 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 13:21:08 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	get_outfile(t_list *lst)
{
	int	fd;

	while (lst->next)
		lst = lst->next;
	fd = open(lst->content, O_RDONLY);
	if (fd == -1)
		error_message(FAILED_FILES_CREATION);
	return (fd);
}

void	cleanup_resources(int **pipefds, pid_t *pids, int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds - 1)
	{
		close(pipefds[i][0]);
		close(pipefds[i][1]);
		i++;
	}
	i = 0;
	while (i < num_cmds)
		waitpid(pids[i++], NULL, 0);
	free2dintptr(pipefds, num_cmds);
}
