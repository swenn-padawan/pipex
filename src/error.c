/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:37 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/26 17:28:26 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_message(int error)
{
	if (error == TOO_FEW_ARGS)
	{
		write(2, "\nError: too few args provided!\n", 31);
		exit(0);
	}
	if (error == NO_PATH_FOUND)
	{
		write(2, "\nError: No path found!\n", 23);
		exit(0);
	}
	if (error == NO_FILES)
	{
		write(2, "\nError: File don't exist!\n", 25);
		exit(0);
	}
	if (error == NO_COMMAND_FOUND)
	{
		write(2, "\nError: Command not found!\n", 27);
		exit(0);
	}
}
