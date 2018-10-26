#include "ft_md5.h"
#include <stdio.h>

void		ft_set_value(t_sign *sign)
{
	size_t		bin_len;

	bin_len = sign->mess_len * 8;
	sign->end_piece_len = sign->mess_len % 64;	
	sign->piece_nbr = sign->mess_len / 64;
	sign->end_piece[sign->end_piece_len] = 128;
	if (sign->end_piece_len <= 55 && sign->end_piece_len)
	{
		ft_memcpy(sign->end_piece, sign->message + sign->mess_len - sign->end_piece_len, 
					sign->end_piece_len);
		ft_memcpy((sign->end_piece + 56), &(bin_len), sizeof(size_t));
	}
	else if (sign->end_piece_len)
	{
		sign->adbit = 1;
		ft_memcpy(sign->end_piece, sign->message + sign->mess_len - sign->end_piece_len, 
					sign->end_piece_len);
		ft_memcpy((sign->adbittoend + 56), &(bin_len), sizeof(size_t));
	}
	else
		ft_memcpy((sign->end_piece + 56), &(bin_len), sizeof(size_t));
}
