#include "ft_ssl_md5.h"

static void		ft_md5_edd(t_proxy *prox, char const *f_name, t_flags *f)
{
	size_t	i;
	unsigned char *conv;
	
	i = 0;
	conv = NULL;
	while (i < 16)
	{
		conv = (unsigned char *)&prox->a + i * sizeof(unsigned char);
		ft_hex_output(*conv);
		i++;
	}
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
}	

void	ft_md5_output(unsigned char *map, size_t size, char const *f_name, t_flags *f)
{
	t_proxy prox;

	prox.a = 0;
	prox.b = 0;
	prox.c = 0;
	prox.d = 0;
	prox = ft_mk_md5(map, size);
	if (!f->q && !f->r && !f->stdin)
	{
		ft_putstr("MD5 (");
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
	ft_md5_edd(&prox, f_name, f);
	ft_putendl("");
}
