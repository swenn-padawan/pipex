/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:15:09 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/27 13:58:26 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

t_list	*ft_list_init(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*tmp;

	i = 0;
	lst = NULL;
	argv++;
	while (i < argc)
	{
		tmp = ft_lstnew(argv[i]);
		push(tmp, 0);
		ft_lstadd_back(&lst, tmp);
		i++;
	}
	return (lst);
}
