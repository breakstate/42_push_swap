# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 12:53:43 by lvan-gen          #+#    #+#              #
#    Updated: 2017/07/17 09:45:21 by jdamhuis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strcpy.c		\
			ft_strdup.c		\
			ft_strcat.c		\
			ft_strncpy.c	\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c

SRC2	=	ft_atoi.c		\
			ft_isalpha.c	\
			ft_isupper.c	\
			ft_islower.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_isdigit.c	\
			ft_isascii.c	\
			ft_isalnum.c	\
			ft_isprint.c	\
			ft_isspace.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_putchar.c	\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c

SRC3	=	ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_itoa.c		\
			ft_strsplit.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c

SRC4	=	ft_lstmap.c		\
			ft_strnlen.c	\
			ft_abs.c		\
			ft_realloc.c	\
			ft_puthex.c		\
			ft_putoct.c		\
			ft_strlower.c	\
			ft_strupper.c	\
			ft_make_2d_arr.c\
			get_next_line.c	\
			ft_free_2d_arr.c\
			ft_dup_2d_arr.c	\

SRCS	=	$(SRC1) $(SRC2) $(SRC3) $(SRC4)

OBJ		=	${SRCS:.c=.o}

CFLAGS	= 	-Werror -Wextra -Wall -c

INC_PATH =	./includes/

HEAD	=	libft.h			\
			get_next_line.h	\

HEADERS	=	$(addprefix $(INC_PATH), $(HEAD))

NAME	=	libft.a

all: $(NAME)

$(NAME): $(SRCS) Makefile
	@echo "------->compliling libft.a<-------"
	@gcc $(CFLAGS) $(SRCS) -I includes/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "-------->libft.a compiled<--------"

clean:
	@rm -rf $(OBJ)
	@echo "--------->libft cleaned<----------"

fclean: clean
	@rm -rf $(NAME)
	@echo "--------->really cleaned<---------"

re: fclean all
	@echo "-------->libft recompiled<--------"

norm:
	@echo "--------------->NORMING LIBFT<-----------------"
	@norminette $(HEADERS)
	@echo "-------------->HEADERS ARE DONE<---------------"
	@norminette $(SRC1)
	@echo "--------------->SRCS1 ARE DONE<----------------"
	@norminette $(SRC2)
	@echo "--------------->SRCS2 ARE DONE<----------------"
	@norminette $(SRC3)
	@echo "--------------->SRCS3 ARE DONE<----------------"
	@norminette $(SRC4)
	@echo "--------------->SRCS4 ARE DONE<----------------"
	@echo "----------------->LIBFT Done:<-----------------"

.PHONY: clean fclean norm all re