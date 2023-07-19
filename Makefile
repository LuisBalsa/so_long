# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 22:02:52 by luide-so          #+#    #+#              #
#    Updated: 2023/07/19 21:38:35 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

# Mandatory files
SRC_FILES = main.c utils.c check_map.c
SRC_DIR = src
SRC = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

# Bonus files
SRC_BONUS_FILES = main_bonus.c check_map_bonus.c exit_bonus.c \
					init_enemy_bonus.c init_game_bonus.c key_press_bonus.c \
					render_move_bonus.c game_loop_bonus.c eric_trump_bonus.c
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
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-O3 #-g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	@make -s -C Libft
	@make -s -C minilibx-linux
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${OBJS} ${LIBFT} ${MINILIBX}
	@echo "\n${NAME} created"

obj/%.o: ${SRC_DIR}/%.c ${HEADER}
	@mkdir -p obj
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "Object $(basename $(notdir $@)) files created"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${HEADER_BONUS}
	@make -s -C Libft
	@make -s -C minilibx-linux
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT} ${MINILIBX}
	@echo "\n${NAME_BONUS} created"

obj_bonus/%.o: ${SRC_BONUS_DIR}/%.c
	@mkdir -p obj_bonus
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "\nObject files created"

clean:
	@make fclean -s -C Libft
	@make clean -s -C minilibx-linux
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r obj obj_bonus
	@echo "\nObject files removed"

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "\n${NAME} removed"

run:
	@MAP_COUNT=$$(find maps -maxdepth 1 -type f | wc -l); \
	read -p "Pick a map, options 0 to $$(($$MAP_COUNT-1)): " MAP_FILE; \
	if [ -x "so_long_bonus" ]; then \
		./so_long_bonus maps/$$MAP_FILE.ber; \
	elif [ ! -x "so_long" ]; then \
		echo "Neither the game so_long nor so_long_bonus was found. Compile the desired game and run again."; \
	else \
		./so_long maps/$$MAP_FILE.ber; \
	fi

runall:
	@MAP_COUNT=$$(find maps -maxdepth 1 -type f | wc -l); \
	read -p "Select starting map (0 to $$((MAP_COUNT-1))): " i; \
	while [ $$i -lt $$MAP_COUNT ]; do \
		echo "Running map $$i..."; \
		if [ -x "so_long_bonus" ]; then \
			output=$$(./so_long_bonus maps/$$i.ber); \
		else \
			output=$$(./so_long maps/$$i.ber); \
		fi; \
		echo "$$output" | grep -q "Congratulations! You managed to drive drunk! 🍺"; \
		if [ $$? -eq 0 ]; then \
			echo "\nMap $$i completed."; \
			i=$$(($$i + 1)); \
		fi; \
		echo "$$output"; \
		if [ $$i -ge $$MAP_COUNT ]; then \
			echo "\nAll maps completed."; \
			break; \
		fi; \
		echo "\nStarting map $$i."; \
		read -p "Continue? (y/n): " choice; \
		if [ $$choice != "y" ]; then \
			break; \
		fi; \
		sleep 1; \
	done

fcleansoft:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r obj obj_bonus
	@echo "\nObject files removed"
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "\n${NAME} removed"

downloadminilibx:
	@wget https://cdn.intra.42.fr/document/document/17753/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz

re: fclean all

rebsoft: fcleansoft bonus

.PHONY: all clean fclean re bonus

#.SILENT:
