/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:14:06 by jochang           #+#    #+#             */
/*   Updated: 2019/03/22 14:14:07 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_size	init_size(void)
{
	t_size	size;

	size.nlink = 0;
	size.pw_name = 0;
	size.gr_name = 0;
	size.st_size = 0;
	size.major = 0;
	size.minor = 0;
	size.m = 0;
	size.f_name = 0;
	size.w_cols = ft_getwincols();
	return (size);
}

static void		set_m(t_info *list, t_size *size)
{
	int		tmp;

	tmp = major(list->info.st_rdev);
	size->major = (tmp > size->major ? tmp : size->major);
	tmp = minor(list->info.st_rdev);
	size->minor = (tmp > size->minor ? tmp : size->minor);
	size->m = 1;
}

static void		set_place(t_size *size)
{
	size->nlink = ft_placevalue(size->nlink);
	size->major = ft_placevalue(size->major);
	size->minor = ft_placevalue(size->minor);
	size->st_size = ft_placevalue(size->st_size);
	if (size->m)
		size->st_size = MAX(2 + size->major + size->minor, size->st_size);
}

t_size			set_size(t_info *list)
{
	t_size			size;
	int				tmp;

	size = init_size();
	while (list)
	{
		size.nlink = (list->info.st_nlink > size.nlink ?
						list->info.st_nlink : size.nlink);
		tmp = ft_strlen(getpwuid(list->info.st_uid)->pw_name);
		size.pw_name = (tmp > size.pw_name ? tmp : size.pw_name);
		tmp = ft_strlen(getgrgid(list->info.st_gid)->gr_name);
		size.gr_name = (tmp > size.gr_name ? tmp : size.gr_name);
		size.st_size = (list->info.st_size > size.st_size ?
						list->info.st_size : size.st_size);
		tmp = ft_strlen(list->name);
		size.f_name = (tmp > size.f_name ? tmp : size.f_name);
		if (S_ISBLK(list->info.st_mode) || S_ISCHR(list->info.st_mode))
			set_m(list, &size);
		list = list->next;
	}
	set_place(&size);
	return (size);
}
