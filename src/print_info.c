/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:42:16 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:42:19 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_date(t_info *a, t_flag *flags)
{
	if (!flags->u)
		write(1, &ctime(&a->info.st_mtime)[4], 12);
	else
		write(1, &ctime(&a->info.st_atime)[4], 12);
	ft_putchar(' ');
}

static void	print_name(t_info *a, int size)
{
	if (S_ISDIR(a->info.st_mode))
		ft_putstr("\033[1;36m");
	else if (a->info.st_mode & S_IXUSR)
		ft_putstr("\033[31m");
	if (S_ISLNK(a->info.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISSOCK(a->info.st_mode))
		ft_putstr("\033[32m");
	else if (S_ISBLK(a->info.st_mode))
		ft_putstr("\033[44m");
	else if (S_ISCHR(a->info.st_mode))
		ft_putstr("\033[34;43m");
	size ? ft_printf("%-*s ", size, a->name) : ft_putstr(a->name);
	ft_putstr("\033[0m");
}

static void	print_link(t_info *a)
{
	char	buf[2048];

	ft_bzero(buf, 2048);
	readlink(a->path, buf, 2047);
	ft_printf(" -> %s", buf);
}

void		print_info(t_info *a, t_size size, t_flag *flags)
{
	if (flags->l)
	{
		print_type(a);
		print_permissions(a);
		ft_printf(" %*d ", size.nlink, a->info.st_nlink);
		flags->g ? 0 :
		ft_printf("%-*s  ", size.pw_name, getpwuid(a->info.st_uid)->pw_name);
		ft_printf("%-*s ", size.gr_name, getgrgid(a->info.st_gid)->gr_name);
		if (S_ISBLK(a->info.st_mode) || S_ISCHR(a->info.st_mode))
		{
			if (size.st_size > size.major + size.minor)
				ft_printf("%*s", size.st_size - size.major - size.minor - 2,
				"");
			ft_printf(" %*d, %*d ", size.major, major(a->info.st_rdev),
									size.minor, minor(a->info.st_rdev));
		}
		else
			ft_printf(" %*d ", size.st_size, a->info.st_size);
		print_date(a, flags);
		print_name(a, 0);
		(S_ISLNK(a->info.st_mode)) ? print_link(a) : 0;
	}
	else
		print_name(a, size.f_name);
	ft_putchar(flags->one || flags->l ? '\n' : ' ');
}
