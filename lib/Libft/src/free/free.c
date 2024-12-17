/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:08:35 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/17 19:00:36 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	free2dptr(void **adress)
{
	int	i = 0;
	while (adress[i])
		free(adress[i++]);
	free(adress);
}
