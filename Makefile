# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 02:09:59 by ysarsar           #+#    #+#              #
#    Updated: 2020/01/11 20:56:00 by ysarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
LIBFT_PATH = libft/
INC = -I ./includes/ -I $(LIBFT_PATH)
SRC_DIR = src/
OBJ_DIR = obj/
FLAGS =	-Wall -Wextra -Werror -ltermcap

SRC_NAME =	display.c \
			keys.c \
			list.c \
			main.c \
			signal.c \
			size.c \
			term.c \
			tool.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_PATH)
		@gcc $(FLAGS) $(OBJS) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
		
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@mkdir -p obj
		@gcc -c $(INC) $^ -o $@

clean:
		@make clean -C $(LIBFT_PATH)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C $(LIBFT_PATH)
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)

re:	fclean all