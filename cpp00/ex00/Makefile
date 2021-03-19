.PHONY: all clean fclean re

# Name of file
NAME		=	megaphone

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs

# List of sources
SRCS_FILES	=	megaphone.cpp
SRCS		=	$(addprefix $(PATH_SRC)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.cpp=.o)))
# INCS		=	$(addprefix $(PATH_INC)/, )

# Commands of compilation
COMP		=	clang++
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_DEB	=	-g3 -fsanitize=address

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

$(NAME): $(OBJS) $(INCS)
	@ (set -x; $(COMP) $(COMP_FLAG) -o $(NAME) $(OBJS) )

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.cpp  $(INCS)
	@ ( set -x; $(COMP) $(COMP_FLAG) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all