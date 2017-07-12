NAME = 

SRCS	=	stack_a_rules.c	\
			rules.c			\

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./

OBJS = $(SRCS:.c=.o)

HEADER = ./push_swap.h

LIBFT_INC = ./libft/includes

all: $(NAME) me

$(NAME): $(SRCS) $(HEADER)
	@clear
	@if [ ! -f ./libft/libft.a ]; then \
		make lib; \
		fi
	@$(CC) -o $(NAME) $(SRCS) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT_INC) \
		-L. ./libft/libft.a
	@echo "------->filler have been complied<---------"

clean:
	@clear
	@make lib_clean
	@echo "------->cleaning done<--------"

fclean: clean
	@clear
	@make lib_fclean
	@rm -f $(NAME)
	@clear
	@echo "------->fclean compleated<--------"

lib:
	@make -C libft/

lib_clean:
	@make -C libft/ clean

lib_fclean:
	@make -C libft/ fclean

lib_re:
	@make -C libft/ re

re: fclean all

me:
	@if [ -f author ]; then \
		rm author; \
	fi
	@if [ ! -f author ]; then \
		whoami > author; \
	fi

norm:
	@clear
	@echo "Norminette:"
	@norminette $(HEADER)
	@echo "-------->Header Done:<---------"
	@norminette $(SRCS)
	@echo "------->Sources Done:<---------"

.PHONY: clean fclean re
