/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:07:31 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:07:33 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "libft.h"

typedef struct			s_proxy256
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		e;
	unsigned int		f;
	unsigned int		g;
	unsigned int		h;
}						t_proxy256;

typedef struct			s_sign256
{
	unsigned char const	*message;
	size_t				mess_len;
	size_t				piece;
	size_t				end_piece_len;
	unsigned char		end_piece[64];
	unsigned char		adbittoend[64];
	t_proxy256			prox;
	char				adbit;
}						t_sign256;

typedef struct			s_dig256
{
	unsigned int				res_arr[16];
}						t_dig256;

typedef struct			s_values
{
	unsigned int		value1;
	unsigned int		value2;
}						t_values;

unsigned int			g_val256[64];

t_proxy256				ft_mk_sha256(unsigned char const *message, size_t len);
t_proxy256				ft_mk_sha224(unsigned char const *message, size_t len);
void					ft_calculate_sum256(t_sign256 *sign);
void					ft_clear(unsigned char *arr);
void					ft_init(t_sign256 *sign);
void					ft_fill_arr(unsigned int *w);
void					ft_clear_arr(unsigned int *arr);
unsigned int			r_ofst(unsigned int val, unsigned int offset);
unsigned int			ft_convert_32(unsigned int val);
size_t					ft_convert_to64(size_t val);

#endif
