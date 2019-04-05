/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:47:07 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:47:08 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	reverse_list(t_info **list)
{
	t_info	*prev;
	t_info	*current;
	t_info	*next;

	prev = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}

void		sort_list(t_info **list, t_flag *flags)
{
	if (flags->f)
		return ;
	merge_sort(list, flags);
	if (flags->t)
		merge_sort(list, flags);
	if (flags->r)
		reverse_list(list);
}
