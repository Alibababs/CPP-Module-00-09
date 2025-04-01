GREEN	= \033[1;32m
RED		= \033[0;31m
BLUE	= \033[0;34m
YELLOW	= \033[1;33m
CYAN	= \033[0;36m
RESET	= \033[0m

NAME		= 	harl

CPP			= 	c++

FLAGS		= 	-Wall -Werror -Wextra -std=c++98 -g3

SRC_DIR		= 	./

SRC_FILES	=	main			\
				Harl			\

SRC			= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))

OBJ			= 	$(SRC:.cpp=.o)

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(RESET)"

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME) executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Done$(RESET)"

re: fclean all

.PHONY: all clean fclean re