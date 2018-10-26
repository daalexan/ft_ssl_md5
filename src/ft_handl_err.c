#include "ft_ssl_md5.h"

static void		ft_error_print(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(-1);
}

static void		ft_edend(int err)
{
	if (err == 4)
		ft_putstr(" : No such file or directory\n");
	if (err == 5)
		ft_error_print(" : Unknown flag\nSupported flags :\
			\n-p echo STDIN to STDOUT and append the checksum to STDOUT\
			\n-q quiet mode\
			\n-r reverse the format of the output\
			\n-s print the sum of the given string\n");
	if (err == 6)
		ft_error_print(" : Failed to map file");
	if (err == 7)
		ft_putendl(" : Failed to close file");
}

// void		ft_error(int err, char const *p_name, char const *f_name)
// {	
// 	if (err == 1 || err == 2 || err == 3)
// 	{
// 		if (err == 1)
// 		{
// 			ft_putstr(p_name);
// 			ft_error_print(" : Undefined Error");
// 		}
// 		if (err == 2)
// 			ft_error_print("usage: ft_ssl command [command opts] [command args]");
// 		if (err == 3)
// 		{
// 			ft_putstr(p_name);
// 			ft_putstr(": Error: ");
// 			ft_putstr(f_name);
// 			ft_error_print(" : is an invalid command\n\nMessage Digest commands:\
// 				\nmd5\nsha256\n");
// 		}
// 	}
// 	else
// 	{
// 		ft_putstr(" : ");
// 		ft_putstr(f_name);
// 		ft_edend(err);
// 	}
// }
