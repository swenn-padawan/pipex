/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/17 10:47:38 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <unistd.h>

//./pipex file1 cm1 cm2 file2

int main(int argc, char **argv, char **envp)
{
	char	*cmd1;
	
	if (argc != 5)
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	cmd1 = pipex_cmd_args(argv, envp);
	printf("%s\n", cmd1);
}
