NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

RM = rm -f

COLOR_MAGENTA		=	\033[0;95m
COLOR_LIGHT_RED     =   \033[0;91m
COLOR_LIGHT_GREEN   =   \033[0;92m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOR_LIGHT_GREEN)Program created successfully!"

$(LIBFT):
	@if [ ! -f "$(LIBFT)" ]; then make -C $(LIBFT_DIR); fi

%.o: %.c
	@echo "$(COLOR_LIGHT_RED)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(COLOR_MAGENTA)"
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
