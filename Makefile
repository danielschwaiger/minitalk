# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:13:24 by dapanciu          #+#    #+#              #
#    Updated: 2022/06/20 18:20:22 by dapanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME	= client
SERVER_NAME = server

LIBFT = ./libft
NAME_LIBFT = libft/libft.a

PRINTF = ./ft_printf
NAME_PRINTF = ft_printf/libftprintf.a

CLIENT_SRCS	= client.c 
SERVER_SOURCES = server.c 

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SANITIZE = -fsanitize=address -g3

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

all: $(NAME_LIBFT) $(NAME_PRINTF) $(CLIENT_NAME) $(SERVER_NAME)

$(NAME_PRINTF):
		make -C $(PRINTF)

$(NAME_LIBFT):
		make -C $(LIBFT)

%.o : %.c $(CLIENT_SRCS)
		@echo "Compiling SOURCES"
		$(CC) $(CFLAGS) -I $(LIBFT) -I $(PRINTF) -c -o $@ $<
		@echo "Succesful Compiling"

%.o : %.c $(SERVER_SOURCES)
		@echo "Compiling SOURCES"
		$(CC) $(CFLAGS) -I $(LIBFT) -I $(PRINTF) -c -o $@ $<
		@echo "Succesful Compiling"

$(CLIENT_NAME): $(CLIENT_OBJS) $(NAME_LIBFT) $(NAME_PRINTF)
		$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(NAME_LIBFT) $(NAME_PRINTF)

$(SERVER_NAME): $(SERVER_OBJECTS) $(CLIENT_OBJS) $(NAME_LIBFT) $(NAME_PRINTF)
		$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJECTS) $(NAME_LIBFT) $(NAME_PRINTF)

sanitize: re
	$(CC) $(SANITIZE) $(NAME_LIBFT) $(NAME_PRINTF)

valgrind: re
	$(CC) $(NAME_LIBFT)  $(NAME_PRINTF)
	$(VALGRIND)

clean: 
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJECTS)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) 
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: libft ft_printf all clean fclean re
