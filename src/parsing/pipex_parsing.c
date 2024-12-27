/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:58:52 by swenn             #+#    #+#             */
/*   Updated: 2024/12/27 06:52:19 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**pipex_parsing(char **envp)
{
	char	**cmd_path;

	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		exit(EXIT_FAILURE);
	cmd_path = ft_split(*envp, ':');
	return (cmd_path);
}

char	*pipex_cmd_args(char *cmd, char **envp)
{
	char	**cmd_path;
	int		i;
	char	*tmp_path;

	if (!cmd || !envp || !*envp)
		exit(EXIT_FAILURE);
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		return (cmd);
	cmd_path = pipex_parsing(envp);
	i = 0;
	while (cmd_path[i])
	{
		tmp_path = ft_strsjoin(3, cmd_path[i], "/", cmd);
		if (access(&tmp_path[4], F_OK) == 0 && access(&tmp_path[4], X_OK) == 0)
		{
			free2dptr((void **)cmd_path);
			return (tmp_path);
		}
		i++;
	}
	free2dptr((void **)cmd_path);
	error_message(NO_COMMAND_FOUND);
	return (NULL);
}
