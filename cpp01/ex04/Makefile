.PHONY: all clean fclean re
##
## Makefile for one file. current dir. no includes
##

# Name of file
NAME		=	ex04

# Name directory

PATH_SRC	=	.
PATH_OBJ	=	.

# List of sources
SRCS_FILES	= 	$(NAME).cpp
OBJS		=	$(SRCS_FILES:.cpp=.o)

# Commands of compilation
COMP		=	clang++
COMP_FLAG	=	-Wall -Werror -Wextra 
COMP_DEB	=	-g3 -fsanitize=address

# Others Command
RM			=	/bin/rm
# SETLIST		=	set -x;
# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	$(NAME)
	@ echo "$(_SUCCESS) Compilation done"

$(NAME): $(OBJS) 
	@ $(SETLIST) $(COMP) $(COMP_FLAG) -o $(NAME) $(OBJS)

%.o : %.cpp 
	@ ( $(SETLIST) $(COMP) $(COMP_FLAG) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(NAME).o
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all