NAME	= minishell

HEADER = ./src/main.h

SRCS = ./src/main.c

OBJ = $(patsubst %.c, %.o, $(SRCS))

CC = gcc
FLAGS = -Wall -Werror -Wextra

READLINE_LIB = -lreadline -L /opt/homebrew/Cellar/readline/8.1.2/lib 
READLINE_INC = -I /opt/homebrew/Cellar/readline/8.1.2/include 

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -I $(HEADER) -o $@ $(READLINE_LIB) 

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(READLINE_INC)

clean:  
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all