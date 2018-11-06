NAME = ft_ssl

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER_MAIN = ./includes/
HEADER_LIBFT = ./includes/libft/
HEADER_MD5 = ./includes/md5/inc/
HEADER_SHA256 = ./includes/sha256/inc/

LIB_FILES = ./includes/libft/
MD5_FILES = ./includes/md5/
SHA256_FILES = ./includes/sha256/
		
FT_SSL_FILES =	src/general.c \
				src/md5_output.c \
				src/hex_output.c \
				src/sha256_output.c \
				src/sha224_output.c \
				src/ft_handl_err.c \
				src/ft_check_func.c \
				src/ft_rdparse.c \
				src/ft_rdfile.c \
				src/ft_term_handle.c

OBJ = $(FT_SSL_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a $(MD5_FILES)md5.a $(SHA256_FILES)sha256.a
	$(CC) -o $(NAME) $(OBJ) $(LIB_FILES)*.o $(MD5_FILES)src/*.o $(SHA256_FILES)src/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_MAIN) -I $(HEADER_LIBFT) -I $(HEADER_MD5) -I $(HEADER_SHA256)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
$(MD5_FILES)md5.a:
	make -C $(MD5_FILES)
$(SHA256_FILES)sha256.a:
	make -C $(SHA256_FILES)
clean:
	make clean -C $(LIB_FILES)
	make clean -C $(MD5_FILES)
	make clean -C $(SHA256_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	make fclean -C $(MD5_FILES)
	make fclean -C $(SHA256_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
