NAME			=	philo

LIBFT			=	

DIR_SRCS		=	srcs/mandatory

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c	print.c	init.c	utils.c	process.c	meal.c	death.c

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
	@$(CC) $(CFLAGS) $(OBJS)  ${HEAD} -o $(NAME)
	@echo "\033[5;1m\033[38;5;117m		philo		\033[0m"


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)


clean:
	@rm -rf ${DIR_OBJS}
	@echo "$(BLUE)philo object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@rm -rf ${NAME}
	@echo "$(MAGENTA)philo executable files cleaned!$(DEF_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re
