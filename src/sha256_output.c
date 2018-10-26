#include "ft_ssl_md5.h"

static unsigned int		convert_to_32(unsigned int val)
{
	return (val << 24 | (val << 8 & 0x00FF0000) | (val >> 8 & 0x0000FF00) |
			(val >> 24 & 0x000000FF));
}

static void	ft_sha256_edd(t_flags *f, const char *f_name)
{
	if (f->r && !f->q && !f->stdin)
	{
		ft_putstr(" ");
		if (f->s)
		{
			ft_putchar('"');
			ft_putstr(f_name);
			ft_putchar('"');
			f->s = 0;
		}
		else
			ft_putstr(f_name);
	}
	ft_putchar('\n');
}

static void	ft_sha_outp(char const *f_name, t_proxy256 *prox, unsigned char *conv, t_flags *f)
{
	size_t	i;

	i = 0;
	if (!f->q && !f->r && !f->stdin)
	{
		ft_putstr("SHA256 (");
		if (f->s)
		{
			ft_putchar('"');
			ft_putstr(f_name);
			ft_putchar('"');
			f->s = 0;
		}
		else
			ft_putstr(f_name);
		ft_putstr(") = ");
	}
	while (i < 32)
	{
		conv = (unsigned char *)&prox->a + i * sizeof(unsigned char);
		ft_hex_output(*conv);
		i++;
	}
	ft_sha256_edd(f, f_name);
}

void	ft_sha256_output(unsigned char *message, size_t len, char const *file, t_flags *f)
{
	t_proxy256		prox;
	unsigned char	*conv;
	size_t			i;
	unsigned int	*ptr;
	(void)f;

	prox.a = 0;
	prox.b = 0;
	prox.c = 0;
	prox.d = 0;
	prox.e = 0;
	prox.f = 0;
	prox.g = 0;
	prox.h = 0;
	conv = NULL;
	ptr = NULL;
	prox = ft_mk_sha256(message, len);
	i = 0;
	while (i < 8)
	{
		ptr = (unsigned int*)(&prox.a + i);
		*ptr = convert_to_32(*ptr);
		i++;
	}
	ft_sha_outp(file, &prox, conv, f);
}
