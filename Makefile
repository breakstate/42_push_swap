PUSH_NAME	=	push_swap_exe

PUSH_MAIN	=	./srcs/ps_main.c

CHECK_NAME	=	checker_exe

CHECK_MAIN	=	./srcs/ch_main.c

SRC		=	verify.c				\
			verify_controller.c 	\

SRC_PATH = ./srcs/

SRCS = $(addprefix $(SRC_PATH), $(SRC))

NAME	=	porg

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./

OBJS = $(SRCS:.c=.o)

HEADER = ./push_swap.h

LIBFT_INC = ./libft/includes

all: $(NAME) me

$(NAME): $(HEADER) $(PUSH_NAME) $(CHECK_NAME)
	@if [ ! -f ./libft/libft.a ]; then \
		make lib; \
		fi
	@make $(PUSH_NAME)
	@make $(CHECK_NAME)
	@echo "-------------------->DONE!<--------------------"

$(PUSH_NAME): $(SRCS) $(PUSH_MAIN)
	@$(CC) -o $(PUSH_NAME) $(SRCS) $(PUSH_MAIN) $(CFLAGS) \
		-I $(INCLUDE) -I $(LIBFT_INC) \
		-L ./libft/ -lft
	@echo "------------->PUSH_SWAP COMPILED<--------------"
	
#gcc ps_main.c verify.c verify_controller.c -L ../libft -lft -I ../libft/includes/

$(CHECK_NAME): $(SRCS) $(CHECK_MAIN)
	@$(CC) -o $(CHECK_NAME) $(SRCS) $(CHECK_MAIN) $(CFLAGS) \
		-I $(INCLUDE) -I $(LIBFT_INC) \
		-L ./libft/ -lft
	@echo "-------------->CHECKER COMPILED<---------------"


clean:
	@rm -f $(OBJS)
	@make lib_clean
	@echo "--------------->PROGRAM CLEANED<---------------"

fclean: clean
	@rm -f $(PUSH_NAME)
	@rm -f $(CHECK_NAME)
	@echo "-------------->FCLEAN COMPLEATED<--------------"
#@make lib_fclean

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
