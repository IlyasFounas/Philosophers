NAME    = philo_bonus
SRC     = srcs/init_bonus.c \
		  srcs/main_bonus.c \
		  srcs/routine_bonus.c \
		  srcs/simulation_bonus.c \
		  srcs/utils_bonus.c

MAKEFLAGS += --no-print-directory

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -Iincludes
CC      = cc

$(NAME): $(OBJ) includes/philo_bonus.h
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/philo_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
