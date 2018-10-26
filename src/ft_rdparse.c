#include "ft_ssl_md5.h"

void	ft_parsing(char **argv, int argc, int type_alg)
{
	t_flags	flags;
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	flags.fill = 0;
	flags.stdin = 0;
	while (++i < argc)
	{
		if (!flags.fill)
		{
			if ((str = ft_read_stdinp(str, &i, &flags, argc, argv)) != NULL)
			{
				ft_stdin_hash(str, type_alg, &flags);
				free(str);
			}
			if (flags.s)
			{
				ft_stdin_hash(argv[i], type_alg, &flags);
				i++;
			}
		}
		if (i == argc || ft_check_err(i, argc, argv))
			break;
		ft_file_hash(argv[i], argv[0], type_alg, &flags);
	}
}

char	*ft_read_stdinp(char *str, int *i, t_flags *flags, int end, char **argv)
{
	ft_check_flags(i, flags, end, argv);
	if (flags->p)
	{
		get_next_line(0, &str);
		flags->stdin = 1;
		ft_putstr(str);
		ft_putchar('\n');
	}
	return (str);
}
