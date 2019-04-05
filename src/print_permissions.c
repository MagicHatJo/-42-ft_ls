/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:26:05 by jochang           #+#    #+#             */
/*   Updated: 2019/03/22 22:26:06 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_permissions(t_info *a)
{
	ft_putchar((a->info.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((a->info.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((a->info.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((a->info.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((a->info.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((a->info.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((a->info.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((a->info.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((a->info.st_mode & S_IXOTH) ? 'x' : '-');
	if (listxattr(a->path, NULL, 0, XATTR_NOFOLLOW))
		ft_putchar('@');
	else
		ft_putchar(' ');
}
