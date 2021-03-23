.PHONY: all clean fclean re

# Name of file
NAME		=	"sedNul"

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs

GARBAGE_FILES =	*.replace
# List of sources
SRCS_FILES	= 	$(shell find $(PATH_SRC) -type f | cut -d/ -f2- )
INC_FILES	=	$(shell find $(PATH_INC) -type f | cut -d/ -f2- )
# SRCS		=	$(addprefix $(PATH_SRC)/, $(SRCS_FILES))
OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS_FILES:.cpp=.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INC_FILES))
DIRS_LIST	=	$(shell ls -R $(PATH_SRC) 2> /dev/null | grep / | cut -d / -f2-3 | cut -d : -f 1)

# Commands of compilation
COMP		=	clang++
COMP_FLAG	=	-Wall -Werror -Wextra -I$(PATH_INC)
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
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ mkdir -p $(PATH_OBJ)/$(DIRS_LIST)

$(NAME): $(OBJS) $(INCS)
	@ $(SETLIST) $(COMP) $(COMP_FLAG) -o $(NAME) $(OBJS)

# $(PATH_OBJ)/%.o : %.cpp  $(INCS)
# 	@ ( $(SETLIST) $(COMP) $(COMP_FLAG) -c $< -o $@ )
# 	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.cpp  $(INCS)
	@ ( $(SETLIST) $(COMP) $(COMP_FLAG) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ $(RM) -rf $(GARBAGE_FILES)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all