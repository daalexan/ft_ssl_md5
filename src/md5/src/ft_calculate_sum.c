/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 03:21:08 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/13 03:21:09 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	ft_porx_func(t_proxy *result, int *i, int *res, int *index)
{
	if (*i >= 0 && *i <= 15)
	{
		res = ((*result.B & *result.C) | (~(*result.B*) & *result.D));
		*index = *i;
	}
	else if (*i >= 16 && *i <= 31)
	{
		*res = ((*result.D & *result.B) | (~(*result.D) & *result.C));
		*index = (5 * (*i) + 1) % 16;
	}
	else if (*i >= 32 && *i <= 47)
	{
		*res = (*result.B ^ *result.C ^ *result.D);
		*index = (3 * (*i) + 5) % 16;
	}
	else if (*i >= 48 && *i <= 63)
	{
		*res = (*result.C ^ (*result.B | ~(*result.D)));
		*index = (7 * (*i)) % 16;
	}
}

int	left_offset(unsigned int res, unsigned int offset)
{
	return ((res << offset) | (res >> (32 - offset)));
}

t_proxy	ft_calculate_sum(t_sign *sign)
{
	t_proxy	result;
	int		i;
	int		res;
	int		index;

	i = -1;
	result.A = sign->A;
	result.B = sign->B;
	result.C = sign->C;
	result.D = sign->D;
	while (++i < 64)
	{
		ft_porx_func(&result, &i, &res, &index);
		res = res + result.A + K[i] + s[index];
		result.A = result.D;
		result.D = result.C;
		result.C = result.B;
		result.B = result.B + left_offset(res, s[index]);
	}
	result.A += sign->A;
	result.B += sign->B;
	result.C += sign->C;
	result.D += sign->D;
	return (result);
}
