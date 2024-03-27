# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:44:12 by mgayout           #+#    #+#              #
#    Updated: 2024/03/13 10:01:31 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
NAME_B	= 	so_long_bonus
CC		=	gcc
CFLAGS	=	-Wextra -Wall -Werror
MFLAGS	=	-lXext -lX11
REMOVE	=	rm -f
SRC_DIR	=	./src/
B_DIR	=	./src/bonus/
LIBMLX	=	./minilibx/libmlx.a
LIBFT	=	./libft/libft.a
LIBPF	=	./ft_printf/libftprintf.a
LIBGN	=	./get_next_line/get_next_line.a

SRCS	=	src/main.c \
			src/image.c \
			src/movement1.c \
			src/movement2.c \
			src/map1.c \
			src/map2.c \
			src/map3.c \
			src/set.c \
	
SRCS_B	=	src/bonus/main_bonus.c \
			src/bonus/image1_bonus.c \
			src/bonus/image2_bonus.c \
			src/bonus/map1_bonus.c \
			src/bonus/map2_bonus.c \
			src/bonus/map3_bonus.c \
			src/bonus/player_bonus.c \
			src/bonus/set1_bonus.c \
			src/bonus/set2_bonus.c \
			src/bonus/movement1_bonus.c \
			src/bonus/movement2_bonus.c \

all: $(LIBFT) $(LIBMLX) $(LIBPF) $(LIBGN) $(NAME)

$(NAME):
			$(CC) $(SRCS) $(LIBFT) $(LIBMLX) $(LIBPF) $(LIBGN) $(CFLAGS) $(MFLAGS) -o $(NAME)

bonus: $(LIBFT) $(LIBMLX) $(LIBPF) $(LIBGN) $(NAME_B)

$(NAME_B):
			$(CC) $(SRCS_B) $(LIBFT) $(LIBMLX) $(LIBPF) $(LIBGN) $(CFLAGS) $(MFLAGS) -o $(NAME_B)

$(LIBFT):
			@make bonus -C libft/

$(LIBMLX):
			@make -C minilibx/

$(LIBPF):
			@make -C ft_printf/

$(LIBGN):
			@make -C get_next_line/

clean:
			
			@make clean -C libft/
			@make clean -C minilibx/
			@make clean -C ft_printf/
			@make clean -C get_next_line/

fclean:
			$(REMOVE) $(NAME) $(NAME_B)

re: fclean all

rebonus: fclean $(NAME_B)

.PHONY: all clean fclean re rebonus
