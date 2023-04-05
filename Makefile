S = src/
O = obj/

include settings.mk

OBJ = $(SRC:%=$O%.o)

RM = /bin/rm -df
RMDIR = /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: % libft.h Makefile settings.mk
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $@ $^

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)

re: fclean all
