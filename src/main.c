/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:43:38 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 19:45:06 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	print_normal(int ac, char **av, t_flag *flags)
{
	int		i;
	int		check;
	t_info	*list;
	t_size	size;

	i = g_optind - 1;
	check = 0;
	list = NULL;
	while (++i < ac)
	{
		if (!ft_isdir(av[i]))
		{
			save_one(&list, av[i], 0);
			check++;
		}
	}
	size = set_size(list);
	loop_iter(list, size, flags);
	free_list(&list);
	return (check);
}

static void	parse_dirs(int ac, char **av, t_flag *flags, int check)
{
	char	*path;
	int		m;

	m = g_optind + 1 < ac ? 1 : 0;
	while (g_optind < ac)
	{
		if (ft_isdir(av[g_optind]))
		{
			check ? ft_putchar('\n') : 0;
			check = 1;
			m ? ft_putstr(av[g_optind]) : 0;
			m ? ft_putendl(":") : 0;
			path = fix_path(av[g_optind], NULL);
			ft_ls(path, flags);
			free(path);
		}
		g_optind++;
	}
}

int			main(int ac, char **av)
{
	t_flag		flags;
	int			check;

	g_optind = 1;
	flags = ft_setopt(ac, av);
	if (g_optind == ac)
		ft_ls(".", &flags);
	flags.f ? 0 : sort_av(ac, &av, g_optind, &flags);
	check = print_normal(ac, av, &flags);
	if (!flags.l && ac - g_optind > 1)
		ft_putchar('\n');
	parse_dirs(ac, av, &flags, check);
	return (0);
}
