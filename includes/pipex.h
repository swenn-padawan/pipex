/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:51 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/28 16:02:57 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/Libft/include/libft.h"

enum	e_error
{
	TOO_FEW_ARGS = 1,
	NO_PATH_FOUND,
	NO_PERMS,
	NO_FILES
};

//ERROR
void	error_message(int error);

#ifndef PIPEX_H
# define PIPEX_H











#endif
