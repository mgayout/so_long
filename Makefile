# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:44:12 by mgayout           #+#    #+#              #
#    Updated: 2025/01/14 11:20:14 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
NAMEB	= 	so_long_bonus

FLAG	=	-Wextra -Wall -Werror
MFLAG	=	-lXext -lX11

SRCDIR	= src
SRCBDIR = bonus
HEADIR	= include

SRC		= $(shell find $(SRCDIR) -name '*.c')
SRCB	= $(shell find $(SRCBDIR) -name '*.c')

PRINTFDIR	=	ft_printf-main
PRINTFURL	=	https://github.com/mgayout/ft_printf/archive/refs/heads/main.tar.gz
PRINTFAR	=	libftprintf.a

GNLDIR		=	get_next_line-main
GNLURL		=	https://github.com/mgayout/get_next_line/archive/refs/heads/main.tar.gz
GNLAR		=	get_next_line.a

MINIDIR		=	minilibx-linux-master
MINIURL		=	https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.tar.gz
MINIAR		=	libmlx.a

AR			=	$(PRINTFDIR)/$(PRINTFAR) $(GNLDIR)/$(GNLAR) $(MINIDIR)/$(MINIAR)

all:	$(NAME)

$(NAME):	$(PRINTFAR) $(GNLAR) $(MINIAR)
					@gcc $(SRC) $(AR) $(FLAG) $(MFLAG) -o $(NAME)

bonus:	$(NAMEB)

$(NAMEB):	$(PRINTFAR) $(GNLAR) $(MINIAR)
					@gcc $(SRCB) $(AR) $(FLAG) $(MFLAG) -o $(NAMEB)

$(PRINTFAR): 
					@if [ ! -d $(PRINTFDIR) ]; then \
						curl -L $(PRINTFURL) -o printf.tar.gz; \
						tar -xzf printf.tar.gz; \
						rm printf.tar.gz; \
					fi
					@make -C $(PRINTFDIR)
#					@cp $(PRINTFDIR)/$(PRINTFAR) .

$(GNLAR):
					@if [ ! -d $(GNLDIR) ]; then \
						curl -L $(GNLURL) -o gnl.tar.gz; \
						tar -xzf gnl.tar.gz; \
						rm gnl.tar.gz; \
					fi
					@make -C $(GNLDIR)
#					@cp $(GNLDIR)/$(GNLAR) .

$(MINIAR):
					@if [ ! -d $(MINIDIR) ]; then \
						curl -L $(MINIURL) -o mini.tar.gz; \
						tar -xzf mini.tar.gz; \
						rm mini.tar.gz; \
					fi
					@make -C $(MINIDIR)
#					@cp $(MINIDIR)/$(MINIAR) .

clean:
					@make clean -C $(PRINTFDIR)
					@make clean -C $(GNLDIR)
					@make clean -C $(MINIDIR)

fclean: clean
					@rm -rf $(NAME) $(NAMEB)
					@make fclean -C $(PRINTFDIR)
					@make fclean -C $(GNLDIR)
					@make fclean -C $(MINIDIR)
					
re:	fclean all

rebonus: fclean bonus

rmL:
					@rm -rf $(PRINTFDIR)
					@rm -rf $(GNLDIR)
					@rm -rf $(MINIDIR)

.PHONY: all bonus clean fclean re rebonus rmL
