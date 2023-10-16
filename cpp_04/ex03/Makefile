# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++98 -g -Wall -Wextra -Werror

# Source files
SRCS = AMateria.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   Character.cpp \
	   MateriaSource.cpp \
	   main.cpp 

# Object files 
OBJS = $(SRCS:.cpp=.o)

# Executable name OR target
NAME = AbstractInterface

RM = rm -f

# Default NAME
all: $(NAME)

# Rule to compile .cpp files into object files
%.o: %.cpp
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