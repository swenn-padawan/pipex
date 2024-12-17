/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:14:47 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/17 18:43:21 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

char	*ft_strsjoin(int size, char *start, ...)
{
	va_list	list;
	char	*str;
	char	*tmp;
	char	*next;

	str = start;
	va_start(list, start);
	tmp = str;
	while (--size)
	{
		next = va_arg(list, char *);
		str = ft_strjoin(str, next);
		push(str, 0);
		if (!*str)
		{
			free(tmp);
			break;
		}
	}
	return (str);
}
