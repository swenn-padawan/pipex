/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:42:10 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 17:01:54 by stetrel          ###   ########.fr       */
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
	t_list	*lst;
	t_pipex	pipex;

	envp = check_args(argc, argv, envp);
	lst = ft_list_init(argc, argv);
	pipex.infile = open(lst->content, O_RDONLY);
	if (pipex.infile == -1)
		error_message(NO_FILES);
	pipex.outfile = get_outfile(lst);
	//while de pipex en parcourant la liste chainees
}
