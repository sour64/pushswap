NAME = push_swap

SRCS = calloc.c firstcheck.c ft_atoi.c ft_split.c main.c operations.c operations2.c separation.c sort.c sort35.c stack.c stackutils.c

HEADER = push_swap.h

CC = gcc

FLAGS = -Wextra -Werror -Wall

OBJS = ${SRCS:%.c=%.o}

all: ${NAME}

${NAME} : $(OBJS)
		$(CC) $(OBJS) -o ${NAME}

%.o		:
		 $(CC) $(FLAGS) $(SRCS) -c

clean	:
		rm -f ${OBJS}

fclean	: clean
		rm -f ${NAME}

re		: fclean all

.PHONY	: all clean fclean re