/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:42:06 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 14:42:06 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdint.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft.h"

typedef struct	s_flag
{
	uint8_t		one:1;
	uint8_t		c_r:1;
	uint8_t		a:1;
	uint8_t		f:1;
	uint8_t		g:1;
	uint8_t		l:1;
	uint8_t		r:1;
	uint8_t		t:1;
	uint8_t		u:1;
	uint8_t		err:1;
}				t_flag;

typedef struct	s_info
{
	char			*name;
	char			*path;
	struct stat		info;
	uint8_t			is_dir;
	int				total;
	struct s_info	*next;
}				t_info;

typedef struct	s_size
{
	int			nlink;
	int			pw_name;
	int			gr_name;
	int			st_size;
	int			major;
	int			minor;
	int			m;
	int			f_name;
	int			w_cols;
}				t_size;

t_flag			ft_setopt(int ac, char **av);
char			*fix_path(char *c_dir, char *str);
void			sort_av(int ac, char ***av, int i, t_flag *flags);
void			ft_ls(char *c_dir, t_flag *flags);
int				get_list(t_info **list, char *c_dir, t_flag *flags);
void			add_list(t_info **list, t_info *tmp);
int				save_one(t_info **list, char *file, int t);
void			sort_list(t_info **list, t_flag *flags);
void			merge_sort(t_info **list, t_flag *flags);
t_size			set_size(t_info *list);
void			loop_iter(t_info *iter, t_size size, t_flag *flags);
void			print_info(t_info *a, t_size size, t_flag *flags);
void			print_type(t_info *a);
void			print_permissions(t_info *a);
int				get_line_capacity(int mlen, int cols);
void			free_list(t_info **list);

#endif
