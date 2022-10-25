# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prrattan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 18:00:38 by prrattan          #+#    #+#              #
#    Updated: 2022/07/12 18:01:10 by prrattan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutated

OBJ_DIR = objs/

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm

SRC_FILE = main
SRCS = $(addsuffix .cpp, $(SRC_FILE))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

HDR_FILE = MutantStack
HDRS = $(addsuffix .hpp, $(HDR_FILE))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp $(HDRS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
