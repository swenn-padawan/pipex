/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:37 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 11:35:21 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	message(char *msg)
{
	static int	flag = 0;

	if (flag == 0)
		write(2, msg, ft_strlen(msg));
	flag = 1;
}

void	error_message(int error)
{
	if (error == TOO_FEW_ARGS)
		message("Error: too few args provided!\n");
	else if (error == NO_PATH_FOUND)
		message("Error: No path found!\n");
	else if (error == NO_FILES)
		message("Error: File don't exist!\n");
	else if (error == NO_COMMAND_FOUND)
		message("Error: Command not found!\n");
	else if (error == FAILED_FILES_CREATION)
		message("Error: Failed file's creation\n");
	else if (error == FORK_FAILED)
		message("Error: A Fork Have Failed!\n");
	exit(0);
}
