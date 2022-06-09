# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 01:05:19 by donghyki          #+#    #+#              #
#    Updated: 2022/06/09 06:30:29 by donghyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -rf
MKDIR			= mkdir -p
RMDIR			= rmdir

SRCS_LIST		= main.c read_elements.c read_map.c valid_cub.c set_cub.c start_game.c raycast.c raycast_dda.c raycast_wall.c 

SRCS			= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRCS_LIST:.c=.o))

LIBFT_DIR		= ./libft
INC_DIR			= ./inc
SRC_DIR			= ./src
OBJ_DIR			= ./obj

LIBFT			= libft.a

MLX_DIR = ./minilibx_opengl_20191021
LIB = -lmlx -framework OpenGL -framework AppKit -lft

all: $(OBJ_DIR) $(LIBFT) $(NAME)

bonus: all

$(OBJ_DIR):
	@$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -L$(MLX_DIR) -L$(LIBFT_DIR) -o $@ $^ $(LIB)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
