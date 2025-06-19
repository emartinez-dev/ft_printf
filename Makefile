# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2024/09/27 18:40:04 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS  = -Wall -Wextra -Werror -MMD -MP
LIB = ar -rcs
RM = rm -rf

SRC_DIR = src/
_SRC = ft_printf.c \
	 ft_parse_chars.c \
	 ft_parse_nums.c \
	 ft_auxiliary.c

INCLUDES = -I ./inc

SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}
DEP = ${OBJ:.o=.d}

${NAME}: ${OBJ}
	@${LIB} $@ $^
	@echo "$(NAME) compiled!"

%.o: %.c
	@${CC} ${INCLUDES} ${CFLAGS} -c $< -o $@

-include $(DEP)

all: ${NAME}

clean:
	@echo "Removing files..."
	@${RM} ${OBJ} ${OBJ:.o=.d} ${BONUS_OBJ} ${BONUS_OBJ:.o=.d} ${DEP}
	@echo "Done!"

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
