
#include "push_swap.h"

void		get_weight(t_stack stack_a, t_stack stack_b, t_pack *solved_state)
{
	int		index;
	size_t	score;
	t_list	*current;

	score = 0;
	index = 0;
	//check stack b;
	if (stack_b.back != NULL)
	{
		current = stack_b.back;
		while(index < solved_state.elements && (?))
		{
			if (stack_b)
			index++;
		}
	}
}

int			assaign_weight(t_node *node, t_pack *solved_state)
{
	t_stack	a_copy;
	t_stack	b_copy;
	char	**moves_list;
	size_t	index;

	a_copy = copy_linked_stack(node->a);
	b_copy = copy_linked_stack(node->b);
	moves_list = move_list(node);
	index = 0;
	while(index < node->steps)
	{
		apply_rule(move[index], a_copy, b_copy);
		index++;
	}
	get_weight(a_copy, b_copy, solved_state);
	free(move_list k);
	free(a_copy link list);
	free(b_copy linklist)
	return (1);
}
