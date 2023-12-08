# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 11:25:09 by hkahsay           #+#    #+#              #
#    Updated: 2023/12/07 17:52:00 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++98 -Wall -Wextra -Werror

HEADERS = Span.hpp

# Source files
SRCS = Span.cpp test.cpp main.cpp
# Object files 
OBJS = $(SRCS:.cpp=.o)

# Executable name OR target
NAME = Span

RM = rm -f

# Default NAME
all: $(NAME)

# Rule to compile .cpp files into object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link the object files into the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to clean the compiled files
clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re