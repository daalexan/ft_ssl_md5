/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clrrotconv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:08:23 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:08:24 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

unsigned int	ft_convert_32(unsigned int val)
{
	return (val << 24 | (val << 8 & 0x00FF0000) |
		(val >> 8 & 0x0000FF00) | (val >> 24 & 0x000000FF));
}

size_t			ft_convert_to64(size_t val)
{
	return (val << 56 | (val << 40 & 0x00FF000000000000) |
		(val << 24 & 0x0000FF0000000000) | (val << 8 & 0x000000FF00000000) |
		(val >> 8 & 0x00000000FF000000) | (val >> 24 & 0x0000000000FF0000) |
		(val >> 40 & 0x000000000000FF00) | (val >> 56 & 0x00000000000000FF));
}

unsigned int	r_ofst(unsigned int val, unsigned int offset)
{
	return ((val >> offset) | (val << (32 - offset)));
}

void			ft_clear_arr(unsigned int *arr)
{
	size_t	i;

	i = 0;
	while (i < 64)
		arr[i++] = 0;
}

void			ft_fill_arr(unsigned int *buf)
{
	unsigned int	v0;
	unsigned int	v1;
	size_t			i;

	i = 0;
	while (i < 16)
	{
		buf[i] = ft_convert_32(buf[i]);
		i++;
	}
	while (i < 64)
	{
		v0 = r_ofst(buf[i - 15], 7) ^ r_ofst(buf[i - 15], 18)
		^ (buf[i - 15] >> 3);
		v1 = r_ofst(buf[i - 2], 17) ^ r_ofst(buf[i - 2], 19)
		^ (buf[i - 2] >> 10);
		buf[i] = buf[i - 16] + v0 + buf[i - 7] + v1;
		i++;
	}
}
