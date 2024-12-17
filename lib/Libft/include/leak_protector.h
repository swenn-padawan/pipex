/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_protector.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 06:42:41 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/17 18:38:04 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAK_PROTECTOR_H
# define LEAK_PROTECTOR_H

# include <stdlib.h>

typedef struct s_lp_list
{
	void				*content;
	struct s_lp_list	*next;
	char				type;
}						t_lp_list;

#endif
