# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++98 -Wall -Wextra -Werror
CFLAGS	+= -pedantic
CFLAGS	+= -Wshadow	

# Colors 

GREEN		= \033[0;32m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m
VIOLET		= \033[0;36m
RED			= \033[0;31m
NONE		= \033[0m

# Source files
SRCS = AMateria.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   Character.cpp \
	   MateriaSource.cpp \
	   main.cpp 

# Object files directory
DIR_OBJ = obj

# Object files 
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:.cpp=.o))

# Executable name OR target
NAME = AbstractInterface

RM = rm -f
RMDIR = rm -rf

# Default NAME
all: $(DIR_OBJ)  $(NAME)

# Rule to create the object files directory
$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

# Rule to compile .cpp files into object files
$(DIR_OBJ)/%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link the object files into the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@printf "$(GREEN) $(NAME) Compilation is OK\n$(NONE)"


# Rule to clean the compiled files
clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	 $(RMDIR) $(DIR_OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re