#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"

typedef struct			s_val
{
	unsigned int				s[64];
	unsigned int				K[64];
}						t_val;

typedef struct			s_dig
{
	unsigned int				res_arr[16];
}						t_dig;

typedef struct			s_proxy
{
	unsigned int				a;
	unsigned int				b;
	unsigned int				c;
	unsigned int				d;
}						t_proxy;

typedef struct			s_sign
{
	unsigned char const			*message;
	size_t				mess_len;
	size_t				piece_nbr;
	size_t				end_piece_len;
	unsigned char				end_piece[64];
	unsigned char				adbittoend[64];
	char				adbit;
	unsigned int				A;
	unsigned int				B;
	unsigned int				C;
	unsigned int				D;
}						t_sign;

t_val					g_val;
t_proxy					ft_mk_md5(unsigned char const *str, size_t size);
void					ft_set_value(t_sign *sign);
void					ft_calculate_sum(t_sign *sign);

#endif
