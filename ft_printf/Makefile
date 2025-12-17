NAME = libftprintf.a

CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = SRCS
SRCS = $(SRCS_DIR)/ft_putchar.c \
       $(SRCS_DIR)/ft_putstr.c \
       $(SRCS_DIR)/ft_putnbr.c \
       $(SRCS_DIR)/ft_putnbr_unsigne.c \
       $(SRCS_DIR)/ft_puthex.c \
       $(SRCS_DIR)/ft_putptr.c \
       $(SRCS_DIR)/ft_printf.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re