#include "ft_md5.h"

static unsigned int	left_offset(unsigned int res, unsigned int offset)
{
	return ((res << offset) | (res >> (32 - offset)));
}

static void			ft_sum_func(size_t i, t_proxy *prox, unsigned int f, unsigned int g, t_dig *dig)
{
	if (i <= 15)
		{
			f = (prox->b & prox->c) | ((~prox->b) & prox->d);
			g = i;
		}
		else if (i <= 31)
		{
			f = (prox->d & prox->b) | ((~prox->d) & prox->c);
			g = (5 * i + 1) % 16;
		}
		else if (i <= 47)
		{
			f = prox->b ^ prox->c ^ prox->d;
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = prox->c ^ (prox->b | (~prox->d));
			g = (7 * i) % 16;
		}
		f += prox->a + g_val.K[i] + dig->res_arr[g];
		prox->a = prox->d;
		prox->d = prox->c;
		prox->c = prox->b;
		prox->b += left_offset(f, g_val.s[i]);
}

// static void			ft_loop_sum(t_sign *e, t_dig *dig)
// {
// 	t_proxy	prox;
// 	unsigned int	f;
// 	unsigned int	g;
// 	size_t	i;

// 	i = 0;
// 	g = 0;
// 	f = 0;
// 	prox.a = e->A;
// 	prox.b = e->B;
// 	prox.c = e->C;
// 	prox.d = e->D;
// 	while (i < 64)
// 	{
// 		ft_sum_func(i, &prox, f, g, dig);
// 		i++;
// 	}
// 	e->A += prox.a;
// 	e->B += prox.b;
// 	e->C += prox.c;
// 	e->D += prox.d;
// }

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
