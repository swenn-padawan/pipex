/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:21:36 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 10:00:55 by stetrel          ###   ########.fr       */
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
