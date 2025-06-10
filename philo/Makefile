NAME    = philo
SRC     = srcs/philo_free.c \
		  srcs/philo_init.c \
		  srcs/philo_main.c \
		  srcs/philo_process.c \
		  srcs/philo_threads_routine.c \
		  srcs/philo_time.c \
		  srcs/philo_utils.c \

MAKEFLAGS += --no-print-directory

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -Iincludes
CC      = cc

$(NAME): $(OBJ) includes/philo.h
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c includes/philo.h | $(OBJ_DIR)
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
