/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:26:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/18 04:08:09 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include "printf.h"
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <sys/stat.h>

typedef struct      s_l
{
  char              *arg;
  struct s_l        *next;
  struct s_l        *prev;
}                   t_l;

typedef struct			s_mylist
{
	t_l    			     	*begin;
}						        t_mylist;

typedef struct      s_pars
{
  t_l               *l;
  t_mylist          *b;
  int               ac;
}                   t_pars;

t_l   				      *l_new(char *arg);
void				        push_back_node(t_l *b_list, t_l *list);
int                 print(int all, int ac, char **av);
int                 print_av(DIR *dir, struct dirent *file, char **av);
int                 print_dir(DIR *dir, struct dirent *file, char *str);
void                dir_regfilenames(struct dirent *file, DIR *dir);
void                title(int ac, char *str);
int                 close_dir(DIR *dir);
int                 is_dir(char *str);
t_pars              *init_data(t_l *l, t_mylist *b);

#endif
