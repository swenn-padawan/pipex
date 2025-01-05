/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:42:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/05 13:49:53 by jlorette         ###   ########.fr       */
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
	if (argc < 6 && !check_here_doc(argv))
		error_message(TOO_FEW_ARGS);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	return (envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	int		flag;

	env.envp = check_args(argc, argv, envp);
	env.argv = argv;
	flag = check_here_doc(argv);
	if (!flag)
		here_doc(env, argc);
	else
		execute_pipeline(env, argc);
	return (0);
}
