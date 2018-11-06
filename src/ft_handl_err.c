/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:47:20 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:47:21 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void		ft_error_print(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(-1);
}

static void		ft_edend(char const *f_name, int err)
{
	ft_putstr(": ");
	ft_putstr(f_name);
	if (err == 4)
		ft_putstr(": No such file or directory\n");
	if (err == 5)
		ft_error_print(": Unknown flag\nSupported flags:\
			\n-p echo STDIN to STDOUT and append the checksum to STDOUT\
			\n-q quiet mode\
			\n-r reverse the format of the output\
			\n-s print the sum of the given string\n");
	if (err == 6)
		ft_error_print(": Failed to read line");
	if (err == 7)
		ft_putendl(": Failed to close file");
}

static void		ft_frst_error(int err, char const *p_name, char const *f_name)
{
	if (err == 1)
	{
		ft_putstr(p_name);
		ft_error_print(": Undefined Error");
	}
	if (err == 2)
		ft_error_print("usage: ft_ssl command [command opts] \
[command args]");
	if (err == 3)
	{
		ft_putstr(p_name);
		ft_putstr(": Error: ");
		ft_putstr(f_name);
		ft_error_print(": is an invalid command\n\nMessage Digest commands:\
			\nmd5\nsha256\nsha224\n");
	}
}

void			ft_error(int err, char const *p_name,
	char const *f_name, char *alg)
{
	p_name += 2;
	if (err == 1 || err == 2 || err == 3)
		ft_frst_error(err, p_name, f_name);
	else
	{
		ft_putstr(p_name);
		ft_putstr(": ");
		ft_putstr(alg);
		ft_edend(f_name, err);
	}
}
