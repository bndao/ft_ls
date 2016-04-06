/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 01:57:17 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 01:57:49 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void 				stickybits_usr(t_l *l)
{
	if (l->s.st_mode & S_IXUSR && l->s.st_mode & S_ISUID)
		ft_printf("s");
	else if (l->s.st_mode & S_ISUID)
		ft_putchar('S');
	else if (l->s.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void 				stickybits_grp(t_l *l)
{
	if (l->s.st_mode & S_IXGRP && l->s.st_mode & S_ISGID)
		ft_putchar('s');
	else if (l->s.st_mode & S_ISGID)
		ft_putchar('S');
	else if (l->s.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void 				stickybits_others(t_l *l)
{
	if (l->s.st_mode & S_IXOTH && l->s.st_mode & S_ISVTX)
		ft_putchar('t');
	else if (l->s.st_mode & S_ISVTX)
		ft_putchar('T');
	else if (l->s.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

char				get_type(t_l *l)
{
	char	c;

	c = '-';
	c = S_ISDIR(l->s.st_mode) ? 'd' : c;
	c = S_ISCHR(l->s.st_mode) ? 'c' : c;
	c = S_ISBLK(l->s.st_mode) ? 'b' : c;
	c = S_ISFIFO(l->s.st_mode) ? 'p' : c;
	c = S_ISLNK(l->s.st_mode) ? 'l' : c;
	c = S_ISSOCK(l->s.st_mode) ? 's' : c;
	return (c);
}

void				print_rights(t_l *l)
{
	char	c;

	if (!l)
		return ;
	ft_putchar(get_type(l));
	ft_putchar(c = (l->s.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWUSR ? 'w' : '-'));
	stickybits_usr(l);
	ft_putchar(c = (l->s.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWGRP ? 'w' : '-'));
	stickybits_grp(l);
	ft_putchar(c = (l->s.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWOTH ? 'w' : '-'));
	stickybits_others(l);
}