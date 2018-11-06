/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:47:11 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:47:12 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void	ft_check_flags(int *i, t_flags *flags, int end, char **argv)
{
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	while (*i < end)
	{
		if (argv[*i][0] != '-')
			break ;
		if (!ft_strcmp(argv[*i], "-p"))
			flags->p = 1;
		else if (!ft_strcmp(argv[*i], "-q"))
			flags->q = 1;
		else if (!ft_strcmp(argv[*i], "-r"))
			flags->r = 1;
		else if (!ft_strcmp(argv[*i], "-s"))
			break ;
		else
			ft_error(5, argv[0], argv[*i], argv[1]);
		(*i)++;
	}
	flags->fill = 1;
}

int		ft_check_err(int i, int argc, char **argv)
{
	if (!ft_strcmp(argv[i], "-p") || !ft_strcmp(argv[i], "-q") ||
		!ft_strcmp(argv[i], "-r"))
	{
		while (i < argc)
		{
			ft_error(4, argv[0], argv[i], argv[1]);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int		ft_check_alorythm(char *argv)
{
	if (!ft_strcmp(argv, "md5"))
		return (0);
	else if (!ft_strcmp(argv, "sha256"))
		return (1);
	else if (!ft_strcmp(argv, "sha224"))
		return (2);
	else
		ft_error(3, "./ft_ssl", argv, argv);
	return (-1);
}
