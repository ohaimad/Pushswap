NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRCS = libft.c main.c main_vars.c libft2.c linked_list.c check.c sort_3_4_5.c chanks/algo2.c chanks/algo.c instructions.c instructions2.c utils.c
SRCS_BONUS = libft.c main_vars.c libft2.c linked_list.c check.c sort_3_4_5.c chanks/algo2.c chanks/algo.c instructions.c instructions2.c utils.c checker_utils.c get_next_line_utils.c get_next_line.c checker.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = pushswap.h

all: $(NAME)

bonus: $(NAME_BONUS)

CC = cc

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re:  fclean all 

# bonus : $(BONUS_OBJS) $(OBJS)
# 	$(NAME)	$(BONUS_OBJS) $(OBJS)