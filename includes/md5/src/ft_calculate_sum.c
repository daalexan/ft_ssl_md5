/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:29:30 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:29:32 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static unsigned int	left_offset(unsigned int res, unsigned int offset)
{
	return ((res << offset) | (res >> (32 - offset)));
}

static void			ft_sum_func(size_t i, t_proxy *prox, t_value *v, t_dig *dig)
{
	if (i <= 15)
	{
		v->f = (prox->b & prox->c) | ((~prox->b) & prox->d);
		v->g = i;
	}
	else if (i <= 31)
	{
		v->f = (prox->d & prox->b) | ((~prox->d) & prox->c);
		v->g = (5 * i + 1) % 16;
	}
	else if (i <= 47)
	{
		v->f = prox->b ^ prox->c ^ prox->d;
		v->g = (3 * i + 5) % 16;
	}
	else
	{
		v->f = prox->c ^ (prox->b | (~prox->d));
		v->g = (7 * i) % 16;
	}
	v->f += prox->a + g_val.k[i] + dig->res_arr[v->g];
	prox->a = prox->d;
	prox->d = prox->c;
	prox->c = prox->b;
	prox->b += left_offset(v->f, g_val.s[i]);
}

static void			ft_loop_sum(t_sign *e, t_dig *dig)
{
	t_proxy			prox;
	t_value			val;
	size_t			i;

	i = 0;
	val.g = 0;
	val.f = 0;
	prox.a = e->a;
	prox.b = e->b;
	prox.c = e->c;
	prox.d = e->d;
	while (i < 64)
	{
		ft_sum_func(i, &prox, &val, dig);
		i++;
	}
	e->a += prox.a;
	e->b += prox.b;
	e->c += prox.c;
	e->d += prox.d;
}

void				ft_calculate_sum(t_sign *sign)
{
	t_dig	*dig;
	size_t	i;

	i = 0;
	while (i < sign->piece_nbr)
	{
		dig = (t_dig *)(sign->message + i * 64);
		ft_loop_sum(sign, dig);
		i++;
	}
	ft_loop_sum(sign, (t_dig *)sign->end_piece);
	if (sign->adbit == 1)
		ft_loop_sum(sign, (t_dig *)sign->adbittoend);
}
