#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "libft.h"

typedef unsigned int uint;

typedef struct					s_proxy256
{
	unsigned int				a;
	unsigned int				b;
	unsigned int				c;
	unsigned int				d;
	unsigned int				e;
	unsigned int				f;
	unsigned int				g;
	unsigned int				h;
}								t_proxy256;

typedef struct					s_sign256
{
	unsigned char const			*message;
	size_t						mess_len;
	size_t						piece;
	size_t						end_piece_len;
	unsigned char				end_piece[64];
	unsigned char				adbittoend[64];
	t_proxy256					prox;
	char						adbit;
}								t_sign256;


typedef struct		s_dig256
{
	uint			res_arr[16];
}					t_dig256;

unsigned int					g_val256[64];

t_proxy256						ft_mk_sha256(unsigned char const *message, size_t len);
void							ft_calculate_sum256(t_sign256 *sign);
void							ft_fill_arr(uint *w);
void							ft_clear_arr(uint *arr);
uint							r_ofst(uint val, uint offset);
uint							ft_convert_32(uint val);
size_t							ft_convert_to64(size_t val);

#endif
