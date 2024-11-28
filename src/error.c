/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:37 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/28 18:24:35 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_message(int error)
{
	if (error == TOO_FEW_ARGS)
	{
		write(2, "Error: too few args provided!\n", 30);
		exit(1);
	}
	if (error == NO_PATH_FOUND)
	{
		write(2, "Error: No path found!\n", 22);
		exit(1);
	}
	if (error == NO_FILES)
	{
		write(2, "Error: File don't exist!\n", 24);
		exit(1);
	}
}
