/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:42:10 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 10:00:48 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <pipex_bonus.h>

int	main(int argc, char **argv, char **envp)
{
	t_list	*lst;
	t_pipex	pipex;

	(void)envp;
	lst = ft_list_init(argc, argv);
	pipex.infile = open(lst->content, O_RDONLY);
	printf("%s\n", (char *)lst->content);
	if (pipex.infile == -1)
		error_message(NO_FILES);
	pipex.outfile = get_outfile(lst);
}
