/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:48:58 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:49:00 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void		ft_stdin_hash(char *str, int type_alg, t_flags *f)
{
	unsigned char	*map;
	size_t			len;
	t_hash			ft_hash;

	ft_hash = ft_init_hash(type_alg);
	len = ft_strlen(str);
	if (!(map = (unsigned char*)malloc(sizeof(unsigned char) * (len))))
		return ;
	ft_strcpy((char*)map, str);
	if (f->stdin)
		map[len] = '\n';
	ft_hash(map, (f->stdin) ? (len + 1) : (len), str, f);
	free(map);
	f->stdin = 0;
}

void		ft_parsing(t_args *arg, int type_alg)
{
	int	i;

	i = 1;
	if (i + 1 == arg->ac)
	{
		i++;
		ft_parse_stdin(i, arg, type_alg);
	}
	else
		ft_parse_filestdin(i, arg, type_alg);
}

int			main(int argc, char **argv)
{
	int		type_alg;
	t_args	arg;

	arg.av = argv;
	arg.ac = argc;
	if (argc == 1)
		ft_term_handle();
	else
	{
		type_alg = ft_check_alorythm(argv[1]);
		ft_parsing(&arg, type_alg);
	}
	return (0);
}
