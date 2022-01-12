# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaskour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:01:08 by yaskour           #+#    #+#              #
#    Updated: 2022/01/10 17:23:18 by yaskour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

framework= -framework OpenGL -framework AppKit
NAME=fdf
cc = gcc
flags = -Wall -Wextra -Werror
SRCS = main_mandatory.c\
	   draw.c\
	   key.c\
	   read.c \
	   menu.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c

BONUS_SRCS = main_bonus.c\
			 key_bonus.c
OBJS =$(SRCS:.c=.o)
INCL= fdf.h

BONUS_OBJS =$(BONUS_SRCS:.c=.o)\
			draw.o\
			read.o\
			menu.o\
			./get_next_line/get_next_line_utils.c\
			./get_next_line/get_next_line.c\

ALL:$(NAME)

libft:
	make -C ./libft
	mv ./libft/libft.a .

%.o: %.c
	$(cc) $(flags) $< -I $(INCL) -c 

$(NAME):$(OBJS) libft
	$(cc) $(flags) $(SRCS) -lmlx  $(framework) libft.a -o $(NAME)

bonus:libft $(BONUS_OBJS)
	$(cc) $(flags) $(BONUS_OBJS) -lmlx  $(framework) libft.a -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@rm -rf ./get_next_line/*.o

fclean:clean
	@rm -rf *.a
	@rm -rf fdf
.PHONY:ALL libft clean fclean
