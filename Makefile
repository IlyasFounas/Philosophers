NAME    = philo
SRC     = srcs/philosophers.c 


MAKEFLAGS += --no-print-directory

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -Ilibft -Iincludes
CC      = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT) $(OBJ) includes/philosophers.h
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/philosophers.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): force
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

all: $(NAME)

force:

.PHONY: all clean fclean re force

