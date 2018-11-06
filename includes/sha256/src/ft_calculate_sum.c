/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:07:52 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:07:54 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static void	ft_calc_offset(t_proxy256 *prox, unsigned int i, t_values *val,
	unsigned int *buf)
{
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	s0;
	unsigned int	maj;

	s1 = r_ofst(prox->e, 6) ^ r_ofst(prox->e, 11) ^ r_ofst(prox->e, 25);
	ch = (prox->e & prox->f) ^ ((~prox->e) & prox->g);
	(val->value1) = prox->h + s1 + ch + g_val256[i] + buf[i];
	s0 = r_ofst(prox->a, 2) ^ r_ofst(prox->a, 13) ^ r_ofst(prox->a, 22);
	maj = (prox->a & prox->b) ^ (prox->a & prox->c) ^ (prox->b & prox->c);
	(val->value2) = s0 + maj;
}

static void	ft_loop_stage(t_proxy256 *prox, unsigned int *buf)
{
	t_values	v;
	size_t		i;

	v.value1 = 0;
	v.value2 = 0;
	i = 0;
	while (i < 64)
	{
		ft_calc_offset(prox, i, &v, buf);
		prox->h = prox->g;
		prox->g = prox->f;
		prox->f = prox->e;
		prox->e = prox->d + v.value1;
		prox->d = prox->c;
		prox->c = prox->b;
		prox->b = prox->a;
		prox->a = v.value1 + v.value2;
		i++;
	}
}

static void	ft_sum_func(t_sign256 *sign, t_dig256 *dig)
{
	t_proxy256		prox;
	unsigned int	buf[64];

	prox.a = sign->prox.a;
	prox.b = sign->prox.b;
	prox.c = sign->prox.c;
	prox.d = sign->prox.d;
	prox.e = sign->prox.e;
	prox.f = sign->prox.f;
	prox.g = sign->prox.g;
	prox.h = sign->prox.h;
	ft_clear_arr(buf);
	ft_memcpy(buf, dig, 64);
	ft_fill_arr(buf);
	ft_loop_stage(&prox, buf);
	sign->prox.a += prox.a;
	sign->prox.b += prox.b;
	sign->prox.c += prox.c;
	sign->prox.d += prox.d;
	sign->prox.e += prox.e;
	sign->prox.f += prox.f;
	sign->prox.g += prox.g;
	sign->prox.h += prox.h;
}

void		ft_calculate_sum256(t_sign256 *sign)
{
	size_t	i;

	i = 0;
	while (i < sign->piece)
	{
		ft_sum_func(sign, (t_dig256 *)(sign->message + i * 64));
		i++;
	}
	ft_sum_func(sign, (t_dig256 *)sign->end_piece);
	if (sign->adbit == 1)
		ft_sum_func(sign, (t_dig256 *)sign->adbittoend);
}
