# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 16:25:19 by fallard           #+#    #+#              #
#    Updated: 2020/08/22 21:09:05 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fallard.filler
VISUAL = visualizer

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD_NAME = filler.h
HVIS_NAME = visual.h
LIB_NAME = libft.a

VIS_DIR = sources/visualisation/
SRC_DIR = sources/algorithm/
INC_DIR = includes/
LIB_DIR = libft/

SRC = main.c \
board.c \
map.c \
piece.c \
heat.c \
algorithm.c \
mem_management.c

SRC_VIS = visual.c \
sdl_init.c \
sdl_game_info.c \
sdl_map.c \
sdl_loop.c \
sdl_draw_players.c \
sdl_draw_map.c \
sdl_draw_results.c \
sdl_free_mem.c

# COLOR
RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

TMP = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
TMP_VIS = $(addprefix $(VIS_DIR), $(SRC_VIS:.c=.o))
HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))
HEAD_VIS = $(addprefix $(INC_DIR), $(HVIS_NAME))
LIBFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

INCLUDES = -I libft/includes -I $(INC_DIR)
SDL_INC = -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(LIBFT) $(NAME) $(VISUAL)
	
$(NAME): $(LIBFT) $(TMP)
	@$(CC) $(CFLAGS) -o $(NAME) $(TMP) $(INCLUDES) -L $(LIB_DIR) -lft
	@printf "$(CN)<< Player $(NAME) created >>\n$(EOC)"

$(VISUAL): $(LIBFT) $(TMP_VIS)
	@$(CC) $(CFLAGS) -o $(VISUAL) $(TMP_VIS) $(INCLUDES) $(SDL_INC) -L $(LIB_DIR) -lft
	@printf "$(CN)<< Program $(VISUAL) created >>\n$(EOC)"

%.o:%.c $(HEADER) $(HEAD_VIS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -f $(TMP)
	@rm -f $(TMP_VIS)
	@make clean -C $(LIB_DIR)
	@printf "$(YW)Filler: $(RD)Object files deleted.\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VISUAL)
	@make fclean -C $(LIB_DIR)
	@printf "$(YW)Filler: $(RD)Player $(NAME) and program $(VISUAL) deleted.\n$(EOC)"

re: fclean all
