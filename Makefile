NAME = push_swap
NAME2 = checker

INCLUDES = 	./srcs/includes

SRC_CHECKER = 	./intructs.c		\
				./main.c			\
				./useintructs.c		\
				./cleanup.c			\
				./error_check.c		\
				./stacks.c

SRC_PUSH_SWAP = ./intructs.c		\
				./push_swap.c		\
				./cleanup.c			\
				./swap_algo.c		\
				./useintructs.c		\
				./error_check.c		\
				./push_intructs.c	\
				./stacks.c

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

all: $(NAME2) $(NAME)

$(NAME): $(SRC_PUSH_SWAP)
	@make -C ./srcs re
	@gcc -Wall -Werror -Wextra -c $(SRC_PUSH_SWAP) -I $(INCLUDES) -g2
	@gcc -Wall -Werror -Wextra $(OBJ_PUSH_SWAP) -L ./srcs -lft -o push_swap -g2
	@echo "push_swap done"

$(NAME2): $(SRC_CHECKER)
	@make -C ./srcs re
	@gcc -Wall -Werror -Wextra -c $(SRC_CHECKER) -I $(INCLUDES) -g2
	@gcc -Wall -Werror -Wextra $(OBJ_CHECKER) -L ./srcs -lft -o checker -g2
	@echo "checker done"

clean:
	@make -C ./srcs clean
	@rm -f $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	@echo "removed object files"

fclean: clean
	@make -C ./srcs fclean
	@rm -f push_swap checker
	@echo "removed push_swap and checker"

re: fclean all
