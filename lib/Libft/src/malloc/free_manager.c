/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:01:33 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 11:24:32 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <leak_protector.h>
#include <libft.h>

static t_lp_list	*lp_lstnew(void *content, char type)
{
	t_lp_list	*node;

	node = malloc(sizeof(t_lp_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->type = type;
	return (node);
}

static void	lp_lstadd_front(t_lp_list **lst, t_lp_list *node)
{
	if (!lst || !node)
		return ;
	node->next = *lst;
	*lst = node;
}

static t_lp_list	**alloc_collector(char type)
{
	static t_lp_list	*lst;

	if (!lst)
		lst = lp_lstnew(NULL, type);
	return (&lst);
}

__attribute__((destructor))
static void	free_alloc_collector(char type)
{
	t_lp_list	**lst;
	t_lp_list	*tmp;

	lst = alloc_collector(type);
	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		tmp = (*lst)->next;
		if ((*lst)->type == 1)
			free2dptr((*lst)->content);
		else
			free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	free(tmp->content);
	free(tmp);
}

void	push(void *malloc_address, char type)
{
	t_lp_list	**lst;

	lst = alloc_collector(type);
	lp_lstadd_front(lst, lp_lstnew(malloc_address, type));
}
