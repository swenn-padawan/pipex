/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:37 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 09:46:05 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_message(int error)
{
	if (error == TOO_FEW_ARGS)
		write(2, "\nError: too few args provided!\n", 31);
	else if (error == NO_PATH_FOUND)
		write(2, "\nError: No path found!\n", 23);
	else if (error == NO_FILES)
		write(2, "\nError: File don't exist!\n", 25);
	else if (error == NO_COMMAND_FOUND)
		write(2, "\nError: Command not found!\n", 27);
	else if (error == FAILED_FILES_CREATION)
		write(2, "\nError: Failed file's creation\n", 31);
	else if (error == FORK_FAILED)
		write(2, "\nError: A Fork Have Failed!\n", 27);
	exit(0);
}
