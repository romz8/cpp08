# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 12:44:24 by romainjober       #+#    #+#              #
#    Updated: 2024/02/23 12:50:08 by romainjober      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = ex00
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I ./ 
HEADER = easyfind.hpp
SRC = main.cpp 
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)
RM = rm -rf

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADER )
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re