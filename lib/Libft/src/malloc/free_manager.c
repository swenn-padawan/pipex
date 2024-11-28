/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:01:33 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/28 15:38:36 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <leak_protector.h>

static t_lp_list	*lp_lstnew(void *content)
{
	t_lp_list	*node;

	node = malloc(sizeof(t_lp_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

static void	lp_lstadd_front(t_lp_list **lst, t_lp_list *node)
{
	if (!lst || !node)
		return ;
	node->next = *lst;
	*lst = node;
}

static t_lp_list	**alloc_collector(void)
{
	static t_lp_list	*lst;

	if (!lst)
		lst = lp_lstnew(NULL);
	return (&lst);
}

__attribute__((destructor))
static void	free_alloc_collector(void)
{
	t_lp_list	**lst;
	t_lp_list	*tmp;

	lst = alloc_collector();
	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	free(tmp->content);
	free(tmp);
}

void	push(void *malloc_address)
{
	t_lp_list	**lst;

	lst = alloc_collector();
	lp_lstadd_front(lst, lp_lstnew(malloc_address));
}
