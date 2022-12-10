# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2022/12/10 17:25:35 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

SRC_DIR = src/
_SRC = ft_printf.c \
	 ft_parse_chars.c \
	 ft_parse_nums.c \
	 ft_auxiliary.c
SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	@${LIB} $@ $^
	@echo "$(NAME) compiled!"

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@

all:
	@${NAME}

clean:
	@echo "Removing files..."
	@${RM} ${OBJ} ${BONUS_OBJ}
	@echo "Done!"

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
