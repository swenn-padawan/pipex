/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:42:10 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/29 11:49:21 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <string.h>

int	check_here_doc(char **argv)
{
	if (strcmp(argv[1], "here_doc"))
		return (1);
	return (0);
}

char	**check_args(int argc, char **argv, char **envp)
{
	if (argc < 5 && check_here_doc(argv))
		error_message(TOO_FEW_ARGS);
	if (argc < 7 && !check_here_doc(argv))
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	return (envp);
}

int	main(int argc, char **argv, char **envp)
{
	envp = check_args(argc, argv, envp);
	execute_pipeline(argv, argc, envp);
}
