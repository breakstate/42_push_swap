#include "push_swap.h"

//this is more of a templeat at the moment

void		expand (t_node *node, t_open open, final_state, stack_a)
{
	//make 7 nodes
//	ft_create_node(stack_a, node->parent, final_state, moves)
}

void		expand_open_set(t_open **open, t_list *final_state,
				t_pack *pack, t_stack *stack_a)
{
	t_closed	*closed;
	t_open	*temp;

	closed = NULL;
	while (*open)
	{
		temp = (*open);
		if (expand ((*open)->node, open) == final_state)
			break ;
		temp->next == NULL;
	//	add_to_closed_set(&closed, temp)
	}
}

void		a_star(t_pack *pack)
{
	t_stack	*stack_a;
	t_list	*final_state;
	t_node	*start;
	t_open	*open;

	stack_a = ft_create_stack(pack->int_arr, pack->elements);
	final_state = sort_list(stack_a->back);
	start = ft_create_node(pack, NULL, final_state, NULL);
	open = NULL;
	ft_add_to_openset(&open, start);
	expand_open_set(&open, final_state, pack, stack_a);
}