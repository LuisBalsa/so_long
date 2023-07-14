# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 22:02:52 by luide-so          #+#    #+#              #
#    Updated: 2023/07/14 20:56:24 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

# Mandatory files
SRC_FILES = main.c utils.c check_map.c
SRC_DIR = src
SRC = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

# Bonus files
SRC_BONUS_FILES = main_bonus.c utils_bonus.c
SRC_BONUS_DIR = src_bonus
SRC_BONUS = ${addprefix ${SRC_BONUS_DIR}/, ${SRC_BONUS_FILES}}

# Object files
OBJS = ${addprefix obj/, ${SRC_FILES:.c=.o}}
OBJS_BONUS = ${addprefix obj_bonus/, ${SRC_BONUS_FILES:.c=.o}}

# Header files same folder
HEADER_FILES = so_long.h
HEADER_BONUS_FILES = so_long_bonus.h
HEADER_DIR = include
HEADER = ${addprefix ${HEADER_DIR}/, ${HEADER_FILES}}
HEADER_BONUS = ${addprefix ${HEADER_DIR}/, ${HEADER_BONUS_FILES}}

#
INCLUDE = -I .
LIBFT = -L Libft_obj -lft
MINILIBX = -L mlx -lmlx -lXext -lX11
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	@make -s -C Libft
	@make -s -C mlx
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${OBJS} ${LIBFT} ${MINILIBX}
	@echo "\n${NAME} created"

obj/%.o: ${SRC_DIR}/%.c
	@mkdir -p obj
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "Object $(basename $(notdir $@)) files created"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${HEADER_BONUS}
	@make -s -C Libft
	@make -s -C mlx
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT} ${MINILIBX}
	@echo "\n${NAME_BONUS} created"

obj_bonus/%.o: ${SRC_BONUS_DIR}/%.c
	@mkdir -p obj_bonus
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "\nObject files created"

clean:
	@make fclean -s -C Libft
	@make clean -s -C mlx
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r obj obj_bonus
	@echo "\nObject files removed"
	@make fclean -s -C Libft

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "\n${NAME} removed"

re: fclean all

.PHONY: all clean fclean re bonus

#.SILENT:
