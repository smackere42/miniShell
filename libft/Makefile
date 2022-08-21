# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:41:18 by kmumm             #+#    #+#              #
#    Updated: 2022/08/21 02:51:49 by kmumm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
HEADER		=	libft.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

DIR_SRC		=	src
DIR_OBJ		=	obj
DIR_SUB		=	gnl \
				is \
				lst \
				malloc_free \
				mem \
				put \
				str \
				to \

INCLUDE		= 	include/

SRC_DIR		=	$(foreach dir, $(DIR_SUB), $(addprefix $(DIR_SRC)/, $(dir)))
OBJ_DIR		=	$(foreach dir, $(DIR_SUB), $(addprefix $(DIR_OBJ)/, $(dir)))

SRC			=	$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ			=	$(subst $(DIR_SRC), $(DIR_OBJ), $(SRC:.c=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

LIBC		=	ar -rcs

#COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[32m"
C_GOOD		=	"\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

$(NAME):	$(OBJ)
			@$(LIBC) $(NAME) $(OBJ)
			@echo "\tCompiling\t" [ $(NAME) ] "\t\t" $(SUCCESS)

$(OBJ): 	| $(OBJ_DIR)

$(OBJ_DIR):
			@mkdir -p $(DIR_OBJ) $(OBJ_DIR)

UP			=	"\033[A"
CUT			=	"\033[K"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c ${INCLUDE}${HEADER} Makefile
				@echo "\tCompiling\t" [$(notdir $<)] "\t\t" $(SUCCESS)
				@${CC} ${CFLAGS} -I ${INCLUDE} -o $@ -c $<
				@printf $(UP)$(CUT)


all			:	$(NAME)  

print :
	@echo $(SRC)
	@echo $(OBJ)

clean		:
				@$(RM_DIR) $(DIR_OBJ)
				@echo "\tCleaning\t" [ $(NAME) ] "\t\t" $(OK)
				
fclean		:	clean
				@$(RM_FILE) $(NAME)
				@echo "\tDeleting\t" [ $(NAME) ] "\t\t" $(OK)

re			:	fclean all

.PHONY		: all clean fclean re bonus print