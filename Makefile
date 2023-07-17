NAME			=	philo

LIBFT			=	libft/libft.a

DIR_SRCS		=	srcs/mandatory

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c	printerror.c	init.c	free_all.c	time.c	process.c

SRCS_NAMES_B	=	

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

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
	@$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	# @echo "\033[5;1m\033[38;5;117m		philo		\033[0m"


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)


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
