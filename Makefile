PUSH_NAME	=	push_swap

PUSH_MAIN	=	push_main.c

CHECK_NAME	=	checker

CHECK_MAIN	=	check_main.c

SRCS	=	ft_linkedlists.c	\
			ft_rules.c			\
			ft_stack_a_b_test.c	\
			ft_stack_test.c		\
			ft_swap.c			\
			ft_mem_manager.c	\
			ft_stack.c			\
			ft_stack_a_test.c	\
			ft_stacks.c			\
			ps_3.c				\

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./

OBJS = $(SRCS:.c=.o)

HEADER = ./push_swap.h

LIBFT_INC = ./libft/includes

all: $(NAME) me

$(NAME): $(SRCS) $(HEADER) $(CHECK_MAIN) $(PUSH_MAIN)
	@clear
	@if [ ! -f ./libft/libft.a ]; then \
		make lib; \
		fi
	@make filler
	@make check
	@echo "------->push_swap prog has been compiled<---------"

push:
	@$(CC) -o $(PUSH_NAME) $(SRCS) $(PUSH_MAIN) $(CFLAGS) \
		-I $(INCLUDE) -I $(LIBFT_INC) \
		-L. ./libft/libft.a
	@echo "------->push_swap has been compiled<---------"

checker:
	@$(CC) -o $(CHECK_NAME) $(SRCS) $(CHECK_MAIN) $(CFLAGS) \
		-I $(INCLUDE) -I $(LIBFT_INC) \
		-L. ./libft/libft.a
	@echo "------->checker has been compiled<---------"

clean:
	@clear
	@rm -f $(OBJS)
	@make lib_clean
	@echo "------->cleaning done<--------"

fclean: clean
	@make lib_fclean
	@rm -f $(PUSH_NAME)
	@rm -f $(CHECK_NAME)
	@echo "------->fclean compleated<--------"

lib:
	@make -C libft/

lib_clean:
	@make -C libft/ clean

lib_fclean:
	@make -C libft/ fclean

lib_re:
	@make -C libft/ re

libft_norm:
	@make -C libft/ norm

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
	@echo "---------------->Header Done:<-----------------"
	@norminette $(SRCS)
	@echo "---------------->Sources Done:<----------------"
	@norminette $(CHECK_MAIN)
	@echo "-------------->Check_main Done:<---------------"
	@norminette $(PUSH_MAIN)
	@echo "--------------->Push_main Done:<---------------"
	@make libft_norm


.PHONY: clean fclean re norm

n: 
	clang nmbotho/*.c -Wall -Wextra -Werror
