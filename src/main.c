/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:14:01 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/14 17:26:27 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <fcntl.h>

//./pipex file1 cm1 cm2 file2

char	*find_path(char **envp, char *cmd1)
{
	char	**paths;
	char	*tmp_path;
	int		i;

	paths = ft_split(*envp, ':');
	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strsjoin(4, 3, paths[i], "/", cmd1);
		if (access(tmp_path, F_OK) == 0 && access(tmp_path, X_OK) == 0)
		{
			free_strs(paths);
			return(tmp_path);
		}
		i++;
	}
	free(tmp_path);
	free_strs(paths);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	char	buffer[10000];
	if (argc != 5)
		return (1);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp)
		return (1);
	char	**args1 = ft_split(argv[2], ' ');
	int fd1 = open(argv[1], O_RDONLY, 0644);
	int	bytes_read = read(fd1, buffer, 10000);
	if (bytes_read == -1)
		return (write(2, "Error\n", 7));
	//int fd2 = open(argv[4], O_CREAT|O_WRONLY, 0644);
	char *path = find_path(envp, argv[2]);
	execve(path, args1, envp);
	printf("%s\n", path);
	free(path);
}

