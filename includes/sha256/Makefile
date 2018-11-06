NAME = sha256.a

HEADER = ../libft/
FILL_HEADER = ./inc/

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ../libft/
MD5_FILES = src/main.c \
			src/sha224main.c \
			src/ft_clrrotconv.c \
			src/ft_calculate_sum.c			
				
OBJ = $(MD5_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	ar rc $(NAME) $(OBJ) $(LIB_FILES)*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I $(FILL_HEADER)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
clean:
	make clean -C $(LIB_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
