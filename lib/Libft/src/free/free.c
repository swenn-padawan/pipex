/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:08:35 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/04 13:21:40 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	free2dptr(void **adress)
{
	int	i;

	i = 0;
	if (!adress)
		return ;
	while (adress[i])
		free(adress[i++]);
	free(adress);
}

void	free2dintptr(int **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size - 1)
		free(tab[i++]);
	free(tab);
}
