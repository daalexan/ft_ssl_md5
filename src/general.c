#include "ft_ssl_md5.h"

static void ft_read_from_file(int fd, char **str)
{
	char buf[1];
	char *tmp;
	int res;

	*str = '\0';
	tmp = (char*)malloc(sizeof(char));
	*tmp = '\0';
	while ((res = read(fd, buf, 1)))
	{
		*str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = ft_strdup(*str);
		ft_strdel(&(*str));
	}
	//printf("buf = %s\n", tmp);
	*str = ft_strjoin(tmp, buf);
	//printf("line = %s\n", *str);
	ft_strdel(&tmp);
}

void	ft_file_hash(char const *f_name, char const *p_name, int type_alg, t_flags *f)
{
	int				fd;
	unsigned char	*map;
	char 			*str;
	size_t			len;

	fd = -1;
	map = NULL;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		ft_error(4, p_name, f_name, (type_alg == 0) ? ("md5") : ("sha256"));
	else
	{
		ft_read_from_file(fd, &str);
		//printf("str1 = %s\n", str);
		len = ft_strlen(str);
		if (!(map = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1))))
			return ;
		ft_strcpy((char*)map, str);
		if (type_alg == 0)
			ft_md5_output(map, len-1, f_name, f);
		else if (type_alg == 1)
			ft_sha256_output(map, len-1, f_name, f);
		if (close(fd) == -1)
			ft_error(7, p_name, f_name, (type_alg == 0) ? ("md5") : ("sha256"));
		free(str);
		free(map);
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
	//free(str);
	//printf("str = %s\n", str);
	f->stdin = 0;
}

int		main(int argc, char **argv)
{
	int		type_alg;

	if (argc == 1)
		ft_error(2, argv[0], NULL, NULL);
	type_alg = ft_check_alorythm(argv);
	ft_parsing(argv, argc, type_alg);
	return (0);
}
