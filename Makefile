#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 16:01:39 by vgrynish          #+#    #+#              #
#    Updated: 2018/12/25 16:01:41 by vgrynish         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vgrynish.filler

FLAGS_AL = -L libft -lft

FLAGS_AI = -Wall -Wextra -Werror  -I incl -I libft/incl

FLAGS_VL = -L libft -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

FLAGS_VI = -Wall -Wextra -Werror -I incl -I libft/incl  -I /usr/local/include

NAME_VISO = viso

ALG = algoritm

VIS = visualizer

OBJ = obj

LIBFT = libft/libft.a

SRC_ALG =	main.c \
			init_map.c \
			init_piece.c \
			find_best_position.c \
			plus_add.c \
			check_big.c

SRC_VIS =	init_map_viso.c \
			bresenham.c \
			draw_map.c \
			main_visu.c \
			add_viso.c

OBG_A = $(addprefix $(OBJ)/, $(patsubst %.c,%.o,$(SRC_ALG)))
OBG_V = $(addprefix $(OBJ)/, $(SRC_VIS:.c=.o))

all: $(LIBFT)	$(NAME) $(NAME_VISO)

$(LIBFT): 
	make -C libft

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(ALG)/%.c | $(OBJ)
	gcc -c $(FLAGS_AI) $< -o $@

$(NAME): $(OBG_A)
	gcc -o $(NAME) $(FLAGS_AL) $(OBG_A)

$(OBJ)/%.o: $(VIS)/%.c | $(OBJ)
	gcc -c $(FLAGS_VI) $< -o $@


$(NAME_VISO): $(OBG_V)
	gcc -o $(NAME_VISO) $(FLAGS_VL) $(OBG_V)

clean:
	 /bin/rm -f $(OBG_V) $(OBG_A)

fclean: clean
	/bin/rm -rf $(NAME) $(OBJ) $(NAME_VISO)

re: fclean all