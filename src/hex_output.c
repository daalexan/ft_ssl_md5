/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:49:05 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/27 19:49:06 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void	ft_hex_output(unsigned char nbr)
{
	static const char	basic[16] = "0123456789abcdef";
	char				show[2];
	size_t				i;

	show[0] = '0';
	show[1] = '0';
	i = 0;
	while (nbr != 0)
	{
		show[i] = basic[nbr % 16];
		nbr /= 16;
		i++;
	}
	ft_putchar(show[1]);
	ft_putchar(show[0]);
}
