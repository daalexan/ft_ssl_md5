#include "ft_ssl_md5.h"

void	ft_file_hash(char const *f_name, char const *p_name, int type_alg, t_flags *f)
{
	int				fd;
	unsigned char	*map;
	char 			*str;
	size_t			len;

	fd = -1;
	map = NULL;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		ft_error(4, p_name, f_name);
	else
	{
		get_next_line(fd, &str);
		len = ft_strlen(str);
		if (!(map = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1))))
			return ;
		ft_strcpy((char*)map, str);
		map[len] = '\n';
		if (type_alg == 0)
			ft_md5_output(map, len + 1, f_name, f);
		else if (type_alg == 1)
			ft_sha256_output(map, len + 1, f_name, f);
		if (close(fd) == -1)
			ft_error(7, p_name, f_name);
		free(str);
	}
}

void	ft_stdin_hash(char *str, int type_alg, t_flags *f)
{
	unsigned char	*map;
	size_t			len;

	len = ft_strlen(str);
	if (!(map = (unsigned char*)malloc(sizeof(unsigned char) * (len))))
		return ;
	ft_strcpy((char*)map, str);
	if (f->stdin)
		map[len] = '\n';
	if (type_alg == 0)
		ft_md5_output(map, (f->stdin) ? (len + 1) : (len), str, f);
	else if (type_alg == 1)
		ft_sha256_output(map, (f->stdin) ? (len + 1) : (len), str, f);
	free(map);
	f->stdin = 0;
}

int		main(int argc, char **argv)
{
	int		type_alg;

	if (argc == 1)
		ft_error(2, argv[0], NULL);
	if (argc == 2)
		ft_error(2, argv[0], NULL);
	type_alg = ft_check_alorythm(argv);
	ft_parsing(argv, argc, type_alg);
	return (0);
}
