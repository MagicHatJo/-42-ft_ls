/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:05:56 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 18:05:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	save_one(t_info **list, char *file, int t)
{
	t_info	*tmp;

	ZERO_CHECK(!(tmp = ft_memalloc(sizeof(t_info))));
	tmp->name = ft_strdup(&file[t]);
	tmp->path = ft_strdup(file);
	if (lstat(tmp->path, &(tmp->info)) == -1)
	{
		ft_printf("ls: ");
		perror(tmp->path);
		free(tmp->name);
		free(tmp->path);
		free(tmp);
		return (0);
	}
	tmp->is_dir = 0;
	add_list(list, tmp);
	return (tmp->info.st_blocks);
}
