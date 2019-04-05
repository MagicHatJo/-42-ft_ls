/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:09:50 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 18:09:51 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		loop_iter(t_info *iter, t_size size, t_flag *flags)
{
	int	check;
	int	cap;

	check = 0;
	cap = get_line_capacity(size.f_name, size.w_cols);
	while (iter)
	{
		(!flags->l && check >= cap && !(check % cap)) ? ft_putchar('\n') : 0;
		print_info(iter, size, flags);
		iter = iter->next;
		check++;
	}
}
