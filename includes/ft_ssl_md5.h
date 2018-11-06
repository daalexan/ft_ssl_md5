/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:44:51 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:44:52 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <fcntl.h>
# include "ft_md5.h"
# include <sys/mman.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "ft_sha256.h"

typedef	struct		s_flags
{
	short			ch;
	short			fill;
	short			stdin;
	short			p;
	short			q;
	short			r;
	short			s;
}					t_flags;

typedef	struct		s_args
{
	char			**av;
	int				ac;
}					t_args;

typedef struct		s_arrays
{
	const char		*f_name;
	const char		*p_name;
}					t_arrays;

typedef	void		(*t_hash)(unsigned char *, size_t, char const *, t_flags *);
typedef	struct stat	t_rdfl;

t_hash				ft_init_hash(int type_alg);
void				ft_md5_output(unsigned char *map, size_t size,\
	char const *f_name, t_flags *flag);
void				ft_sha256_output(unsigned char *map, size_t size,\
	char const *f_name, t_flags *flag);
void				ft_sha224_output(unsigned char *map, size_t size,\
	char const *f_name, t_flags *flag);
void				ft_hex_output(unsigned char num);
void				ft_error(int err, char const *p_name, char const *f_name,
	char *alg);
int					ft_check_err(int i, int argc, char **argv);
int					ft_check_alorythm(char *argv);
void				ft_parsing(t_args *arg, int type_alg);
int					ft_read_stdinp(char **str, int *i, t_flags *flags,\
	t_args *arg);
void				ft_check_flags(int *i, t_flags *flags, int end,\
	char **argv);
void				ft_stdin_hash(char *str, int type_alg, t_flags *f);
void				ft_file_hash(char const *f_name, char const *p_name,\
	int type_alg, t_flags *f);
void				ft_term_handle();
void				ft_parse_stdin(int i, t_args *arg, int type_alg);
void				ft_parse_filestdin(int i, t_args *arg, int type_alg);
char				*ft_alg(int type_alg);
#endif
