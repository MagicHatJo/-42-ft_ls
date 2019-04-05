/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:06:31 by jochang           #+#    #+#             */
/*   Updated: 2019/03/22 16:06:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	def_sort(int ac, char ***av, int start)
{
	int		i;
	int		j;
	char	*tmp;

	i = start - 2;
	while (++i < ac)
	{
		j = i;
		while (++j < ac - 1)
		{
			if (ft_strcmp((*av)[j], (*av)[j + 1]) > 0)
			{
				tmp = (*av)[j];
				(*av)[j] = (*av)[j + 1];
				(*av)[j + 1] = tmp;
			}
		}
	}
}

static void	rev_av(int ac, char ***av, int start)
{
	char	*tmp;

	while (start < ac - 1)
	{
		tmp = (*av)[ac - 1];
		(*av)[ac - 1] = (*av)[start];
		(*av)[start] = tmp;
		ac--;
		start++;
	}
}

void		sort_av(int ac, char ***av, int i, t_flag *flags)
{
	def_sort(ac, av, i);
	if (flags->r)
		rev_av(ac, av, i);
}
