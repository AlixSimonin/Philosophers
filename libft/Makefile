NAME = libft.a
SRCS =	ft_free.c \
		ft_free_tab.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_split.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS} 
.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all


.PHONY:	all clean fclean re 
