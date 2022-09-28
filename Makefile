NAME = minishell

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a

SRC_DIR	=	mandatory
RM_FILE		=	rm -f

all:	
		@make -C ${LIBFT_DIR}/ all
		@make -C ${SRC_DIR}/ all
		@rm -f ${NAME}
		@cp ${SRC_DIR}/${NAME} ${NAME}

clean:
		@make -C ${LIBFT_DIR}/ clean
		@make -C ${SRC_DIR}/ clean
		
fclean:	
		@make -C ${LIBFT_DIR}/ fclean	
		@make -C ${SRC_DIR}/ fclean
		@${RM_FILE} $(NAME)

run:
		@./minishell

re:		fclean all

.PHONY: all bonus clean fclean re run
