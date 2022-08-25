# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:13:24 by dapanciu          #+#    #+#              #
#    Updated: 2022/08/25 14:49:10 by dapanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME	= client
SERVER_NAME = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_BONUS_SOURCES = client_bonus.c minitalk_bonus.c 
SERVER_BONUS_SOURCES = server_bonus.c minitalk_bonus.c
						
LIBFT = ./libft
NAME_LIBFT = libft/libft.a

PRINTF = ./ft_printf
NAME_PRINTF = ft_printf/libftprintf.a

CLIENT_SRCS	= client.c \
			  minitalk.c 
			  
SERVER_SOURCES = server.c \
				 minitalk.c 	

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

CLIENT_BONUS_OBJ =  $(CLIENT_BONUS_SOURCES:.c=.o)
SERVER_BONUS_OBJ = $(CLIENT_BONUS_SOURCES:.c=.o)


CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SANITIZE = -fsanitize=address -g3

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

#.SILENT:

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

bonus: $(NAME_LIBFT) $(NAME_PRINTF) $(CLIENT_BONUS) $(SERVER_BONUS) 

	$(NAME_PRINTF):
		make -C $(PRINTF)

	$(NAME_LIBFT):
		make -C $(LIBFT)
	
	 %.o : %.c $(SERVER_BONUS_SOURCES)
		@echo "Compiling SOURCES"
		$(CC) $(CFLAGS) -I $(LIBFT) -I $(PRINTF) -c -o $@ $<
		@echo "Succesful Compiling"

	%.o : %.c $(CLIENT_BONUS_SOURCES)
		@echo "Compiling SOURCES"
		$(CC) $(CFLAGS) -I $(LIBFT) -I $(PRINTF) -c -o $@ $<
		@echo "Succesful Compiling"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(NAME_LIBFT) $(NAME_PRINTF)
		$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(NAME_LIBFT) $(NAME_PRINTF)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(NAME_LIBFT) $(NAME_PRINTF)
		$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(NAME_LIBFT) $(NAME_PRINTF)
	
re: fclean all 

.PHONY: libft ft_printf all clean bonus fclean re
