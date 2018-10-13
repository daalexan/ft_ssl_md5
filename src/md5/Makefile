NAME = md5

HEADER = ./inc/libft/
FILL_HEADER = ./inc/

SRC = src

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ./inc/libft/
FILLER_FILES =  src/main.c \
				src/ft_set_values.c \
				src/ft_calculate_sum.c
				
OBJ = $(FILLER_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	$(CC) -o $(NAME) $(OBJ) $(LIB_FILES)*.o

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
