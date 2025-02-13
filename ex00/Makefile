GREEN	= \033[1;32m
RED		= \033[0;31m
BLUE	= \033[0;34m
YELLOW	= \033[1;33m
CYAN	= \033[0;36m
RESET	= \033[0m

NAME		=	megaphone

CPP			=	c++

FLAG		=	-Wall -Werror -Wextra -std=c++98 -g3

CPP_FILE	=	megaphone

SRC_DIR		=	./

SRC			=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(CPP_FILE)))

OBJ			=	$(SRC:.c=.o)

.c.o:
	@$(CPP) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CPP) $(OBJ) $(FLAG) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(RESET)"

clean:
	@echo "$(RED)Deleting $(NAME) object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME) executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Done$(RESET)"

re: fclean all

.PHONY: all clean fclean re
