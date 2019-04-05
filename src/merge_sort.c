/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:47:18 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:47:19 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		timecmp(t_info *a, t_info *b, t_flag *flags)
{
	if (flags->u)
		return (b->info.st_atime - a->info.st_atime);
	return (b->info.st_mtime - a->info.st_mtime);
}

static void		split(t_info *head, t_info **a, t_info **b)
{
	t_info	*slow;
	t_info	*fast;

	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
	return ;
}

static t_info	*merge_sorted(t_info *a, t_info *b, t_flag *flags)
{
	t_info	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((flags->t ? timecmp(a, b, flags) : ft_strcmp(a->name, b->name)) <= 0)
	{
		result = a;
		result->next = merge_sorted(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = merge_sorted(a, b->next, flags);
	}
	return (result);
}

void			merge_sort(t_info **list, t_flag *flags)
{
	t_info	*head;
	t_info	*a;
	t_info	*b;

	head = *list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	*list = merge_sorted(a, b, flags);
	return ;
}
