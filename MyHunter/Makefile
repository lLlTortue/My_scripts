##
## EPITECH PROJECT, 2024
## my_hunter.c
## File description:
## Makefile
##

NAME    :=  my_hunter

SRC :=  $(shell find * -name '*.c')

BUILD_DIR	:=	build

OBJ	:=	${SRC:%.c=$(BUILD_DIR)/%.o}

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-audio -lcsfml-system

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(@D)
	gcc -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean  all

run:	re
	./$(NAME)
	@echo -n "cleaning... "
	@make --silent fclean
	@echo Done
