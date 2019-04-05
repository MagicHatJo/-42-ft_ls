/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:40:32 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 15:40:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*fix_path(char *c_dir, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (!str)
	{
		if (c_dir[0] == '~' || c_dir[0] == '/' || c_dir[0] == '.')
			return (ft_strdup(c_dir));
		return (ft_strjoin("./", c_dir));
	}
	tmp = ft_strjoin(c_dir, "/");
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	return (tmp2);
}
