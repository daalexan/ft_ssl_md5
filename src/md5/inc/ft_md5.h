/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 02:26:56 by daalexan          #+#    #+#             */
/*   Updated: 2018/10/13 02:26:58 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"
# include <stdio.h> //delete

typedef struct			s_values
{
	unsigned int		s[64];
	unsigned int		K[64];
}						t_values;

typedef	struct			s_sign
{
	const unsigned char	*message;
	const unsigned char *chng_mess;
	unsigned int		A;
	unsigned int		B;
	unsigned int		C;
	unsigned int		D;
}						t_sign;

typedef	struct			s_proxy
{
	unsigned int		A;
	unsigned int		B;
	unsigned int		C;
	unsigned int		D;
}						t_proxy;

void					ft_set_values(t_sign *sign);
t_proxy					ft_calculate_sum(t_sign *sing);

#endif
