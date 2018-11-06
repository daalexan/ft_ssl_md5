/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:41:49 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/28 13:41:50 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

t_proxy256	ft_mk_sha224(unsigned char const *message, size_t len)
{
	t_sign256	sign;

	sign.message = message;
	sign.mess_len = len;
	sign.piece = 0;
	sign.end_piece_len = 0;
	ft_clear(sign.end_piece);
	ft_clear(sign.adbittoend);
	sign.prox.a = 0xC1059ED8;
	sign.prox.b = 0x367CD507;
	sign.prox.c = 0x3070DD17;
	sign.prox.d = 0xF70E5939;
	sign.prox.e = 0xFFC00B31;
	sign.prox.f = 0x68581511;
	sign.prox.g = 0x64F98FA7;
	sign.prox.h = 0xBEFA4FA4;
	sign.adbit = 0;
	ft_init(&sign);
	ft_calculate_sum256(&sign);
	return (sign.prox);
}
