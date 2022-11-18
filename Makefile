NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FILES = ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isdigit \
		ft_isascii \
		ft_isprint \
		ft_itoa \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_memchr \
		ft_memcmp \
		ft_split \
		ft_strchr \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strdup \
		ft_strrchr \
		ft_strncmp \
		ft_tolower \
		ft_toupper \
		ft_atoi \
		ft_strnstr \
		ft_calloc \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))
.c.o:	$(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $@ $^

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY:	all clean fclean re
