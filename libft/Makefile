NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME1 = ft_putchar.c \
			 ft_putstr.c \
			 ft_putendl.c \
			 ft_strlen.c \
			 ft_putnbr.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_isupper.c \
			 ft_islower.c \
			 ft_isalpha.c \
			 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_toupper.c \
			 ft_tolower.c \

SRCS_NAME2 = ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memccpy.c \
			 ft_memmove.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strdup.c \
			 ft_strcpy.c \
			 ft_strncpy.c \
			 ft_strcat.c \
			 ft_strncat.c \
			 ft_strlcat.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strcmp.c \
			 ft_strncmp.c \

SRCS_NAME3 = ft_strstr.c \
			 ft_strnstr.c \
			 ft_atoi.c \
			 ft_memalloc.c \
			 ft_memdel.c \
			 ft_strnew.c \
			 ft_strclr.c \
			 ft_striter.c \
			 ft_striteri.c \
			 ft_strmap.c \
			 ft_strmapi.c \
			 ft_strsub.c \
			 ft_strjoin.c \
			 ft_strtrim.c \
			 ft_strequ.c \
			 ft_strnequ.c \
			 ft_strdel.c \
			 ft_strsplit.c \

SRCS_NAME4 = ft_itoa.c \
			 ft_abs.c \
			 ft_isintmin.c \
			 ft_strnlen.c  \
			 ft_iswhitespace.c \
			 get_next_line.c \
			 ft_getnbr.c \

SRCS4 = $(addprefix $(SRCS_PATH), $(SRCS_NAME4))

SRCS3 = $(addprefix $(SRCS_PATH), $(SRCS_NAME3))

SRCS2 = $(addprefix $(SRCS_PATH), $(SRCS_NAME2))

SRCS1 = $(addprefix $(SRCS_PATH), $(SRCS_NAME1))

SRCS = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

HEADER = 	$(INCLUDES_PATH)libft.h \

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME1:.c=.o) $(SRCS_NAME2:.c=.o) $(SRCS_NAME3:.c=.o) $(SRCS_NAME4:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: $(NAME) 

odir:
	@mkdir -p $(OBJS_PATH)

$(NAME): odir $(OBJS) 
	@make me
	@echo " - libft objects made"
	@echo " - Making $(NAME)"
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@clear
	@echo " - libft Make/all Done!"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling in libft $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

clean:
	@echo " - Cleaning objs in libft"
	@rm -f $(OBJS)
	@clear
	@echo " - Clean Done! in libft"

fclean: clean
	@clear
	@echo " - Cleaning executable in libft"
	@rm -f $(NAME)
	@echo " - fclean Done! in libft"

re: fclean all
	@echo " - re Done! in libft"

format: norm

me:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi;	 

remo:
	if [ -a author ] ; \
		then \
		rm author ; \
		fi;

norm:
	@echo "Norminette:"
	@norminette $(HEADER)
	@echo "Header Done:"
	@norminette $(SRCS1)
	@echo "SRCS1 Done:"
	@norminette $(SRCS2)
	@echo "SRCS2 Done:"
	@norminette $(SRCS3)
	@echo "SRCS3 Done:"
	@norminette	$(SRCS4)
	@echo "SRCS4 Done:"
	@echo " - Norm done"

.PHONY: clean fclean re odir
