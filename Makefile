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

FILES_BONUS = ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES_BONUS)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY:	all clean fclean re
