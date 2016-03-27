/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 06:59:50 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:45:23 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					find_char(char **av, char c)
{
	int				i;
	int				j;
	struct stat		s;

	j = 1;
	while (av[j])
	{
		if (stat(av[j], &s) == 0)
			return (0);
		if (av[j][0] == '-')
		{
			i = 0;
			while (av[j][i])
			{
				if (av[j][i] == c && is_opt(av[j]))
					return (1);
				i++;
			}
		}
		j++;
	}
	return (0);
}

int					is_opt(char *fmt)
{
	int			i;
	struct stat s;

	i = 0;
	if (fmt[0] == '-' && !fmt[1] && stat(fmt, &s) != 0)
		return (0);
	if (fmt[0] != '-' || !fmt[1] || fmt[1] == '-')
		return (0);
	while (fmt[i])
	{
		if (fmt[i] != '-' && fmt[i] != '1' && fmt[i] != 'l' && fmt[i] != 'R' &&
				fmt[i] != 'a' && fmt[i] != 'r' && fmt[i] != 't' &&
				fmt[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

t_opt				*get_opt(int ac, char **av)
{
	t_opt	*o;

	if (!(o = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	o->av = av;
	o->ac = ac;
	o->one = find_char(av, '1');
	o->l = find_char(av, 'l');
	o->rm = find_char(av, 'R');
	o->a = find_char(av, 'a');
	o->r = find_char(av, 'r');
	o->t = find_char(av, 't');
	return (o);
}
