# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 11:41:05 by ahel-bah          #+#    #+#              #
#    Updated: 2022/02/20 21:52:30 by ahel-bah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_2 = client
NAME_BNS = server_bonus
NAME_BNS_2 = client_bonus
C = gcc
F = -Wall -Wextra -Werror
CLI = client.c
SRV = server.c
CLI_BNS = client_bonus.c
SRV_BNS = server_bonus.c
CLI_BNS_OBJ = $(CLI_BNS:.c=.o)
SRV_BNS_OBJ = $(SRV_BNS:.c=.o)
CLI_OBJ = $(CLI:.c=.o)
SRV_OBJ = $(SRV:.c=.o)

all: $(NAME) $(NAME_2)

%.o: %.c
	$(C) $(F) -c $<

$(NAME): $(SRV_OBJ)
	$(C) $(F) $(SRV_OBJ) -o $(NAME)

$(NAME_2): $(CLI_OBJ)
	$(C) $(F) $(CLI_OBJ) -o $(NAME_2)

bonus: $(NAME_BNS) $(NAME_BNS_2)

$(NAME_BNS): $(SRV_BNS_OBJ)
	$(C) $(F) $(SRV_BNS_OBJ) -o $(NAME_BNS)

$(NAME_BNS_2): $(CLI_BNS_OBJ)
	$(C) $(F) $(CLI_BNS_OBJ) -o $(NAME_BNS_2)

clean:
	rm -rf $(CLI_OBJ) $(SRV_OBJ) $(CLI_BNS_OBJ) $(SRV_BNS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_2) $(NAME_BNS_2) $(NAME_BNS)

re: fclean all
