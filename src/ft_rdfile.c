/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:21:55 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/28 14:21:56 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void		ft_close_error(t_arrays *name, int type_alg)
{
	if (type_alg == 0)
		ft_error(7, name->p_name, name->f_name, "md5");
	else if (type_alg == 1)
		ft_error(7, name->p_name, name->f_name, "sha256");
	else if (type_alg == 2)
		ft_error(7, name->p_name, name->f_name, "sha224");
}

char			*ft_alg(int type_alg)
{
	if (type_alg == 0)
		return ("md5");
	else if (type_alg == 0)
		return ("sha256");
	else if (type_alg == 0)
		return ("sha224");
	return ("undefined");
}

static void		ft_calc_hash(t_arrays *name, int type_alg, t_flags *f, int fd)
{
	unsigned char	*map;
	t_rdfl			file_stat;
	t_hash			ft_hash;

	map = MAP_FAILED;
	ft_hash = ft_init_hash(type_alg);
	if ((fstat(fd, &file_stat)) == -1)
		ft_error(4, name->p_name, name->f_name, ft_alg(type_alg));
	if (file_stat.st_size == 0)
		ft_hash(map, file_stat.st_size, name->f_name, f);
	else
	{
		if ((map = mmap(NULL, file_stat.st_size, PROT_READ,
			MAP_PRIVATE, fd, 0)) == MAP_FAILED)
			ft_error(6, name->p_name, name->f_name, ft_alg(type_alg));
		ft_hash(map, file_stat.st_size, name->f_name, f);
		if (munmap(map, file_stat.st_size) == -1)
			ft_error(6, name->p_name, name->f_name, ft_alg(type_alg));
	}
	if (close(fd) == -1)
		ft_close_error(name, type_alg);
}

void			ft_file_hash(char const *f_name, char const *p_name,
	int type_alg, t_flags *f)
{
	int			fd;
	t_arrays	arg;

	if ((fd = open(f_name, O_RDONLY)) == -1)
	{
		if (type_alg == 0)
			ft_error(4, p_name, f_name, "md5");
		else if (type_alg == 1)
			ft_error(4, p_name, f_name, "sha256");
		else if (type_alg == 2)
			ft_error(4, p_name, f_name, "sha224");
	}
	else
	{
		arg.f_name = f_name;
		arg.p_name = p_name;
		ft_calc_hash(&arg, type_alg, f, fd);
	}
}
