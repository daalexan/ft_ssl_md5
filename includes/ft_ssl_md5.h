#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
# include "ft_md5.h"
# include <stdlib.h>
# include "ft_sha256.h"
# include <stdio.h>

typedef	struct	s_flags
{
	short		fill;
	short		stdin;
	short		p;
	short		q;
	short		r;
	short		s;
}				t_flags;

void			ft_md5_output(unsigned char *map, size_t size,\
	char const *filename, t_flags *flag);
void			ft_sha256_output(unsigned char *map, size_t size,\
	char const *filename, t_flags *flag);
void			ft_hex_output(unsigned char num);
void			ft_error(int err, char const *p_name, char const *f_name);
int				ft_check_err(int i, int argc, char **argv);
int				ft_check_alorythm(char **argv);
void			ft_parsing(char **argv, int argc, int type_alg);
char			*ft_read_stdinp(char *str, int *i, t_flags *flags, int end, char **argv);
void			ft_check_flags(int *i, t_flags *flags, int end, char **argv);
void			ft_stdin_hash(char *str, int type_alg, t_flags *f);
void			ft_file_hash(char const *f_name, char const *p_name,\
	int type_alg, t_flags *f);

#endif
