/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:14:47 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/09 18:34:09 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

char	*ft_strsjoin(int free_flag, int size, char *start, ...)
{
	char	*str;
	va_list	list;

	va_start(list, start);
	str = start;
	while (size - 1)
	{
		str = ft_strjoin(str, va_arg(list, char *));
		if (free_flag == 0)
			free(va_arg(list, char *));
		free_flag--;
		size--;
	}
	return (str);
}
