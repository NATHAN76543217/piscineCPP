.PHONY: all clean fclean re

# Name of file
NAME		=	megaphone

# Name directory
PATH_OBJ	=	objs

# List of sources
SRCS_FILES	=	Megaphone.cpp

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS_FILES:.cpp=.o)))
# INCS		=	$(addprefix $(PATH_INC)/, )

# Commands of compilation
COMP		=	clang++
COMP_FLAG	=	-Wall -Werror -Wextra

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ mkdir -p $(PATH_OBJ)

$(NAME): $(OBJS)
	@ ($(COMP) $(COMP_FLAG) -o $(NAME) $(OBJS) )

$(PATH_OBJ)/%.o : ./%.cpp 
	@ ($(COMP) $(COMP_FLAG) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all