/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:52 by daalexan          #+#    #+#             */
/*   Updated: 2018/11/01 14:27:53 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

t_hash			ft_init_hash(int type_alg)
{
	t_hash		func_hash[3];

	func_hash[0] = &ft_md5_output;
	func_hash[1] = &ft_sha256_output;
	func_hash[2] = &ft_sha224_output;
	return (func_hash[type_alg]);
}

static void		ft_hash(char *str, int type_alg, t_flags *f)
{
	unsigned char	*map;
	size_t			len;
	t_hash			func_hash;

	func_hash = ft_init_hash(type_alg);
	len = ft_strlen(str);
	if (!(map = (unsigned char*)malloc(sizeof(unsigned char) * (len))))
		return ;
	if (len == 0)
		func_hash(map, len, str, f);
	else
	{
		ft_strcpy((char*)map, str);
		func_hash(map, len, str, f);
		free(map);
	}
	f->stdin = 0;
}

static char		*ft_merge_lines(char *tmp, char *line)
{
	size_t	len;
	char	*result;
	int		i;

	i = -1;
	len = 0;
	if (tmp)
		len += ft_strlen(tmp);
	if (line)
		len += ft_strlen(line);
	if (!(result = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	if (tmp)
	{
		while (*tmp != '\0')
			result[++i] = *tmp++;
	}
	if (line)
	{
		while (*line != '\0')
			result[++i] = *line++;
		result[i + 1] = '\0';
	}
	return (result);
}

static char		*ft_read_term(int *type_alg)
{
	char	line[256];
	char	*str;
	char	*tmp;
	int		res;

	while ((res = read(0, line, 256)) > 0)
	{
		if (tmp)
			ft_strdel(&tmp);
		line[res] = '\0';
		if (*type_alg == -1)
		{
			line[res - 1] = '\0';
			*type_alg = ft_check_alorythm(line);
			continue;
		}
		if (str)
			tmp = ft_strdup(str);
		if (str)
			ft_strdel(&str);
		str = ft_merge_lines(tmp, line);
	}
	ft_strdel(&tmp);
	return (str);
}

void			ft_term_handle(void)
{
	int		type_alg;
	t_flags	f;
	char	*str;

	f.p = 0;
	f.q = 0;
	f.r = 0;
	f.s = 0;
	f.stdin = 1;
	type_alg = -1;
	str = ft_read_term(&type_alg);
	if (type_alg != -1)
		ft_hash(str, type_alg, &f);
	ft_strdel(&str);
}
