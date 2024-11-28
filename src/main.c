/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/28 17:58:10 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>
#include <unistd.h>

//./pipex file1 cm1 cm2 file2

int main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*cmd1;
	int		i;

	int *ptr = malloc(12);
	push(ptr);
	if (argc != 5)
		error_message(TOO_FEW_ARGS);
	cmd1 = argv[2];
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		error_message(NO_PATH_FOUND);
	paths = ft_split(*envp, ':');
	i = 0;
	while (paths[i])
		printf("%s\n", paths[i++]);
	free_strs(paths);
}
