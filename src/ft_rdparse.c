#include "ft_ssl_md5.h"

static void	ft_parse_filestdin(int i, char **argv, int argc, int type_alg)
{
	t_flags	flags;
	char	*str;

	str = NULL;
	flags.fill = 0;
	flags.stdin = 0;
	while (++i < argc)
	{
		if (!flags.fill)
		{
			if (ft_read_stdinp(&str, &i, &flags, argc, argv))
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
			return;
		ft_file_hash(argv[i], argv[0], type_alg, &flags);
	}
}

static void	ft_parse_stdin(int i, char **argv, int argc, int type_alg)
{
	t_flags	flags;
	char	*str;

	str = NULL;
	flags.fill = 0;
	flags.stdin = 0;
	if (!flags.fill)
	{
		if (ft_read_stdinp(&str, &i, &flags, argc, argv))
		{
			ft_stdin_hash(str, type_alg, &flags);
			free(str);
		}
		if (flags.s)
		{
			ft_stdin_hash(argv[i], type_alg, &flags);
		}
	}
}

void	ft_parsing(char **argv, int argc, int type_alg)
{
	int	i;
	
	i = 1;
	if (i + 1 == argc)
	{
		i++;
		ft_parse_stdin(i, argv, argc, type_alg);
	}
	else
		ft_parse_filestdin(i, argv, argc, type_alg);	
}

static short ft_check_file(int *i, t_flags *f, char **argv)
{
	int cur;

	cur = *i;
	if (f->s)
	{
		cur++;
		if (argv[cur] == NULL)
			return (1);
		else
			return (0);
	}
	else
	{
		if (argv[cur] == NULL)
			return (0);
		else
			return (1);
	}
}

int	ft_read_stdinp(char **str, int *i, t_flags *flags, int end, char **argv)
{
	short	arg;

	ft_check_flags(i, flags, end, argv);
	arg = ft_check_file(i, flags, argv);
	if (flags->p)
	{
		get_next_line(0, str);
		flags->stdin = 1;
		ft_putstr(*str);
		ft_putchar('\n');
		return (1);
	}
	else if (arg == 0)
	{
		get_next_line(0, str);
		flags->stdin = 1;
		return (1);
	}
	return (0);
}
