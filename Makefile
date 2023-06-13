NAME			=	philo

NAME_B			=	

PRINTF			=

LIBFT			=	libft/libft.a

DIR_SRCS		=	srcs/mandatory

#DIR_BONUS		=	srcs/bonus

DIR_OBJS		=	objs

#DIR_OBJS_B		=	objs_bonus

SRCS_NAMES		=	main.c  

SRCS_NAMES_B	=	

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

#OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

#SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

#OBJS_B			=	$(addprefix $(DIR_OBJS_B)/,$(OBJS_NAMES_B))

HEAD			=	-Iincludes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m

all				:	${NAME}

$(NAME): $(OBJS)
	@make -C libft
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[5;1m\033[38;5;117m		philo		\033[0m"


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

#$(DIR_OBJS_B)/%.o: $(DIR_BONUS)/%.c | $(DIR_OBJS_B)
#	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

#$(DIR_OBJS_B):
#	mkdir -p $(DIR_OBJS_B)

#bonus: $(OBJS_B)
#	@make -C libft
#	@make -C ft_printf
#	@$(CC) $(CFLAGS) $(OBJS_B) ${OBJS_GNL} ${LIBFT} ${PRINTF} ${HEAD} -o $(NAME)
#	@echo "\033[5;1m\033[38;5;141m		pipex bonus		\033[39m"

clean:
	@make clean -C libft
	@rm -rf ${DIR_OBJS}
	@echo "$(BLUE)philo object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@make fclean -C libft
	@rm -rf ${LIBFT}
	@rm -rf ${NAME}
	@echo "$(MAGENTA)philo executable files cleaned!$(DEF_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re
