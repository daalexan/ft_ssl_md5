#include "ft_ssl_md5.h"

void	ft_hex_output(unsigned char num)
{
	static const char	base[16] = "0123456789abcdef";
	char				display[2] = "00";
	size_t				i = 0;

	while (num != 0)
	{
		display[i] = base[num % 16];
		num /= 16;
		i++;
	}
	ft_putchar(display[1]);
	ft_putchar(display[0]);
}
