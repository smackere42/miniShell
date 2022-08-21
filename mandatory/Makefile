NAME	= minishell
DIRS	=	main \
			executor \
			parser \

LIBFT= ../libft/libft.a
OBJ_DIR = obj
SRC_DIR = src


C_DIRS	=	$(foreach dir, $(DIRS), $(addprefix $(SRC_DIR)/, $(dir)))
O_DIRS	=	$(foreach dir, $(DIRS), $(addprefix $(OBJ_DIR)/, $(dir)))
C_FILES		=	$(foreach dir, $(C_DIRS), $(wildcard $(dir)/*.c))
H_FILES		=	$(foreach dir, $(C_DIRS), $(wildcard $(dir)/*.h))
O_FILES		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(C_FILES:.c=.o))
H_FILES_INC = $(addprefix -I, $(H_FILES))

CC = gcc
FLAGS = -Wall -Werror -Wextra

READLINE_LIB = -lreadline -L /opt/homebrew/Cellar/readline/8.1.2/lib 
READLINE_INC = -I /opt/homebrew/Cellar/readline/8.1.2/include 

C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"
UP			=	"\033[A"
CUT			=	"\033[K"
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIBFT) $(O_FILES) $(H_FILES) $(C_FILES)
	@$(CC) ${FLAGS} $(O_FILES) -o $@ $(READLINE_LIB) $(LIBFT) 
	@echo "\tCompiling\t" [ $(NAME) ] "\t\t" $(SUCCESS)

print:
	@echo "C_FILES\t" $(C_FILES)
	@echo "O_FILES\t" $(O_FILES)
	@echo "H_FILES\t" $(H_FILES)
	@echo "O_DIRS\t" $(O_DIRS)

$(O_FILES):  |$(O_DIRS)


$(O_DIRS):
		@mkdir -p $(O_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${H_FILES} Makefile $(C_FILES)
		@echo "\tCompiling\t" [$(notdir $<)] "\t\t" $(SUCCESS)
		@${CC} ${FLAGS} $(H_FILES_INC) -o $@ -c $< $(READLINE_INC)
		@printf $(UP)$(CUT)

clean:  
	@rm -rf $(OBJ_DIR)
	@echo "\tCleaning\t" [ $(NAME) ] "\t\t" $(OK)

fclean: clean
	@rm -rf $(NAME)
	@echo "\tDeleting\t" [ $(NAME) ] "\t\t" $(OK)

re: fclean all

.PHONY: all clean fclean re bonus print
