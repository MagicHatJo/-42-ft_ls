/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:01:52 by jochang           #+#    #+#             */
/*   Updated: 2019/03/22 15:01:53 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(t_info *a)
{
	if (S_ISREG(a->info.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(a->info.st_mode))
		ft_putchar('d');
	else if (S_ISBLK(a->info.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(a->info.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(a->info.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(a->info.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(a->info.st_mode))
		ft_putchar('s');
	else
		ft_putchar('?');
}
