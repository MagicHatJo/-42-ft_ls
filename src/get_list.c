/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:31:22 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:31:23 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	save_list(t_info **list, char *c_dir, struct dirent *de)
{
	t_info	*tmp;

	ZERO_CHECK(!(tmp = ft_memalloc(sizeof(t_info))));
	tmp->name = ft_strdup(de->d_name);
	tmp->path = fix_path(c_dir, de->d_name);
	if (lstat(tmp->path, &(tmp->info)) == -1)
	{
		ft_printf("ls: ");
		perror(tmp->path);
		free(tmp->name);
		free(tmp->path);
		free(tmp);
		return (0);
	}
	tmp->is_dir = (S_ISDIR(tmp->info.st_mode) ? 1 : 0);
	add_list(list, tmp);
	return (tmp->info.st_blocks);
}

int			get_list(t_info **list, char *c_dir, t_flag *flags)
{
	struct dirent	*de;
	DIR				*dr;
	int				total;

	total = 0;
	if (!(dr = opendir(c_dir)))
	{
		save_one(list, c_dir, 2);
		return (0);
	}
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.' || flags->a)
			total += save_list(list, c_dir, de);
	closedir(dr);
	return (total);
}
