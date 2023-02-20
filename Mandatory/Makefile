NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = libft.c main.c libft2.c src1.c src2.c \

OBJS = $(SRCS:.c=.o)

HEADER = pushswap.h

all: $(NAME)

CC = cc

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:  fclean all 

# bonus : $(BONUS_OBJS) $(OBJS)
# 	$(NAME)	$(BONUS_OBJS) $(OBJS)