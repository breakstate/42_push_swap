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
**	------------------\
**	applying the rules
**	have to change these
**	------------------/
*/

void			apply_rule(char *rule, t_stacks *stacks);

/*
**	in file stack_a_rules.c
*/

void			sa(t_stacks *stacks);
void			pa(t_stacks *stacks);
void			ra(t_stacks *stacks);
void			rra(t_stacks *stacks);

/*
**	in file stack_b_rules.c
*/

void			sb(t_stacks *stacks);
void			pb(t_stacks *stacks);
void			rb(t_stacks *stacks);
void			rrb(t_stacks *stacks);

/*
**	in file stack_ab_rules.c
*/

void			ss(t_stacks *stacks);
void			rr(t_stacks *stacks);
void			rrr(t_stacks *stacks);

#endif
