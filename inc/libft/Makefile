NAME        = libft.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
LIB         = ar -rcs

FILES       = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
              ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy \
              ft_memmove ft_memset ft_strchr ft_strlcat ft_strlen \
              ft_strncmp ft_strrchr ft_tolower ft_toupper

SRCS        = $(addsuffix .c, $(FILES))
OBJS        = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re