# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 17:29:16 by kdoulyaz          #+#    #+#              #
#    Updated: 2022/08/20 08:34:13 by kdoulyaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

cc == @gcc -g

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

HEADER = philo.h

SRC_FILES = src/main.c src/err.c src/utils.c src/time.c src/thread.c\
			src/actions.c src/checker.c

SRC = $(SRC_FILES)

OBJ = $(SRC:c=o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling philos..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -pthread -o philo
	@echo "\033[0;32m\nDone !"

%.o: %.c
	@printf "\033[0;33mGenerating philos objects... %-10.10s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re bonus