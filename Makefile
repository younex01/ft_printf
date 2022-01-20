NAME = libftprintf.a
INC = ft_printf.h
SRCS = ft_printf.c ft_putadr.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putusd.c ft_bonus.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
AR = ar rcs

all: $(NAME)
bonus: all
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean: clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
