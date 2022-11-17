SRC = ./ft_bzero.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_split.c \
		./ft_strchr.c \
		./ft_strlcat.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strdup.c \
		./ft_strrchr.c \
		./ft_strncmp.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_atoi.c \
		./ft_strnstr.c \
		./ft_calloc.c \
		./ft_substr.c \
		./ft_strjoin.c


CFLAGS = -Wall -Wextra -Werror -I.
OBJ = ${SRC:.c = .o}
NAME = libft.a
$(NAME): ${OBJ}
			gcc $(CFLAGS) -c *.c
			ar rcs ${NAME} *.o
all: ${NAME}
clean:
		rm -f ./*.o
fclean: clean
		rm -f ${NAME}
re: fclean clean
