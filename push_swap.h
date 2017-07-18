#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*
**	-----------------\
**	structs structure
**	-----------------/
*/

typedef struct	s_stacks
{
	int			*stack_a;
	int			*stack_b;
	size_t		size_of_stack;
}				t_stacks;

/*
**	-----------------\
**	struct for int arr
**	-----------------/
*/

typedef struct	s_pack
{
	int			*int_arr;
	int			elements;
}				t_pack;


/*
**	in file ps_verify.c
*/

int				verify_dup(char *arg);
int				verify_digits(char *arg);
int				verify_min_max(long num);
int				verify_int(char **arg);
int				arr_stoi(char **arg, t_pack *pack);
int				verify_args(char *arg, t_pack *pack);
int				verify_argc(int argc);

#endif
