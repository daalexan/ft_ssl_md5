/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:47:43 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:47:45 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void		ft_flag_s_read(int *i, t_args *arg, int type_alg, t_flags *f)
{
	if (!ft_strcmp("-s", arg->av[*i]))
	{
		while (*i < arg->ac)
		{
			f->s = 1;
			if (arg->av[*i + 1])
				ft_stdin_hash(arg->av[*i + 1], type_alg, f);
			else
				ft_error(6, arg->av[0], arg->av[*i], ft_alg(type_alg));
			*i += 2;
			if (*i == arg->ac || ft_strcmp("-s", arg->av[*i]))
				return ;
		}
		f->s = 0;
	}
}

static void		ft_hlp(int *i, t_args *arg, int type_alg, t_flags *f)
{
	if (!f->ch)
	{
		ft_flag_s_read(i, arg, type_alg, f);
		f->ch = 1;
	}
}

void			ft_parse_filestdin(int i, t_args *arg, int type_alg)
{
	t_flags	flags;
	char	*str;

	flags.fill = 0;
	flags.stdin = 0;
	flags.ch = 0;
	while (++i < arg->ac)
	{
		if (!flags.fill)
		{
			if (ft_read_stdinp(&str, &i, &flags, arg))
			{
				ft_stdin_hash(str, type_alg, &flags);
				free(str);
			}
		}
		if (i == arg->ac)
			return ;
		ft_hlp(&i, arg, type_alg, &flags);
		if (i == arg->ac)
			return ;
		ft_file_hash(arg->av[i], arg->av[0], type_alg, &flags);
	}
}

void			ft_parse_stdin(int i, t_args *arg, int type_alg)
{
	t_flags	flags;
	char	*str;

	str = NULL;
	flags.fill = 0;
	flags.stdin = 0;
	if (!flags.fill)
	{
		if (ft_read_stdinp(&str, &i, &flags, arg))
		{
			ft_stdin_hash(str, type_alg, &flags);
			free(str);
		}
	}
}

int				ft_read_stdinp(char **str, int *i, t_flags *flags, t_args *arg)
{
	short	argum;

	ft_check_flags(i, flags, arg->ac, arg->av);
	if (arg->av[*i] == NULL)
		argum = 0;
	else
		argum = 1;
	if (flags->p)
	{
		get_next_line(0, str);
		flags->stdin = 1;
		ft_putstr(*str);
		ft_putchar('\n');
		return (1);
	}
	else if (argum == 0)
	{
		get_next_line(0, str);
		flags->stdin = 1;
		return (1);
	}
	return (0);
}
