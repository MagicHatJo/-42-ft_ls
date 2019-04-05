/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:03:56 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 18:03:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_list(t_info **list)
{
	t_info	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->name);
		free((*list)->path);
		free(*list);
		*list = tmp;
	}
}
