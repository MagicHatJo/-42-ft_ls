/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:28:02 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:28:03 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		recur(t_info *iter, t_flag *flags)
{
	while (iter)
	{
		if (iter->is_dir &&
			ft_strcmp(iter->name, ".") &&
			ft_strcmp(iter->name, ".."))
		{
			ft_putchar('\n');
			ft_ls(iter->path, flags);
		}
		iter = iter->next;
	}
}

void			ft_ls(char *c_dir, t_flag *flags)
{
	t_info		*list;
	t_info		*iter;
	t_size		size;
	int			total;
	static int	m;

	list = NULL;
	total = get_list(&list, c_dir, flags);
	sort_list(&list, flags);
	if (m && flags->c_r)
		ft_printf("%s:\n", &c_dir[ft_strncmp(c_dir, "././", 4) ? 0 : 2]);
	(total && list && flags->l) ? ft_printf("total %d\n", total) : 0;
	iter = list;
	size = set_size(list);
	loop_iter(iter, size, flags);
	flags->l || flags->one ? 0 : ft_putchar('\n');
	m = 1;
	(flags->c_r) ? recur(list, flags) : 0;
	free_list(&list);
}
