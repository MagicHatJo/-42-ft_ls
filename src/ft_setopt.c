/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:54:36 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 14:54:37 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		err_invopt(void)
{
	ft_printf("ls: invalid option -- '%c'\n", g_optopt);
	exit(1);
}

static t_flag	init_flags(void)
{
	t_flag		flags;

	flags.one = 0;
	flags.c_r = 0;
	flags.a = 0;
	flags.f = 0;
	flags.g = 0;
	flags.l = 0;
	flags.r = 0;
	flags.t = 0;
	flags.u = 0;
	flags.err = 0;
	return (flags);
}

static t_flag	set_flags(char c, t_flag flags)
{
	flags.one = (c == '1' ? 1 : flags.one);
	flags.c_r = (c == 'R' ? 1 : flags.c_r);
	flags.a = (c == 'a' || c == 'f' ? 1 : flags.a);
	flags.f = (c == 'f' ? 1 : flags.f);
	flags.g = (c == 'g' ? 1 : flags.g);
	flags.l = (c == 'l' || c == 'g' ? 1 : flags.l);
	flags.r = (c == 'r' ? 1 : flags.r);
	flags.t = (c == 't' ? 1 : flags.t);
	flags.u = (c == 'u' ? 1 : flags.u);
	return (flags);
}

t_flag			ft_setopt(int ac, char **av)
{
	t_flag		flags;
	int			opt;

	flags = init_flags();
	while ((opt = ft_getopt(ac, av, "1Rafglrtu")) != -1)
	{
		if (opt == '?')
			err_invopt();
		flags = set_flags(opt, flags);
	}
	return (flags);
}
