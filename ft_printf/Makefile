# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:59:21 by dapanciu          #+#    #+#              #
#    Updated: 2022/06/20 18:07:18 by dapanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_print_hexa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putnbr_u.c \

OBJ = $(SRC:.c=.o)

CC = gcc
AR = ar csr
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SANITIZE = -fsanitize=address -g3
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

all: $(NAME)

$(OBJ): %.o : %.c
		@echo "Compiling SRC and LIBF Makefile"
		$(CC) $(CFLAGS) -c $< -o $@
		@echo "Succesful Compiling"

$(NAME) : $(OBJ)
		@echo "Creating printf library"
		$(AR) $(NAME) $^
		@echo "Succesfully creating library"


clean :
	$(RM) $(OBJ)


fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re