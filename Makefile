# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaskour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:01:08 by yaskour           #+#    #+#              #
#    Updated: 2022/01/12 18:19:26 by yaskour          ###   ########.fr        #
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

BONUS_SRCS = main_bonus.c\
			 key_bonus.c
OBJS =$(SRCS:.c=.o)
INCL= fdf.h

BONUS_OBJS =$(BONUS_SRCS:.c=.o)\
			draw.o\
			read.o\
			menu.o\

GNL_SRC = get_next_line.c\
		  get_next_line_utils.c

GNL_OBJS =$(GNL_SRC:.c=.o)
all:utils $(NAME)

libft:
	@make -C ./libft
	@mv ./libft/libft.a .

gnl:$(GNL_OBJS)

utils:gnl libft
%.o: %.c $(INCL)
	$(cc) $(flags) $< -I $(INCL) -c
$(NAME):$(OBJS)
	$(cc) $(flags) $(OBJS) $(GNL_OBJS) -lmlx $(framework) libft.a -o $(NAME)

bonus:$(BONUS_OBJS) utils
	$(cc) $(flags) $(BONUS_OBJS) $(GNL_OBJS) -lmlx  $(framework) libft.a -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@rm -rf ./get_next_line/*.o

fclean:clean
	@rm -rf *.a
	@rm -rf fdf
re:fclean all
.PHONY:ALL libft gnl clean fclean
