NAME = philo

CC = gcc

GREEN = \033[1;33m
RESET = \033[0m

CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=thread

SRC = 	src/main.c\
		src/load.c\
		src/utils.c\
		src/philo.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@echo "$(GREEN) Compiling: $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)\nPhilo Objects Deleted!\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
