#include "push_swap.h"

char		**move_list(t_node *node)
{
	char	**moves_list;
	size_t	index;
	t_node	*current;

	moves_list = (char **)malloc(sizeof(char *) * (node->steps + 1);
	if (moves_list)
	{
		current = node;
		moves_list[node->steps] = (char *)malloc(sizeof(char) * 1);
		moves_list[node->steps] = '\0'
		index = node->steps - 1;
		while ((index <= 0) && (current != NULL) && (current->move != NULL))
		{
			moves_list[index] = ft_strdup((const char *)current->move);
			index--;
			current = node->parent;
		}
	}
	return (moves_list);
}

void		apply_rule(char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp("SA", move) == 0)
		ft_SA_SB(a);
	if (ft_strcmp("SB", move) == 0)
		ft_SA_SB(b);
	if (ft_strcmp("SS", move) == 0)
		ft_SS(a, b);
	if (ft_strcmp("PA", move) == 0)
		ft_PA_PB(a);
	if (ft_strcmp("PB", move) == 0)
		ft_PA_PB(b);
	if (ft_strcmp("RA", move) == 0)
		ft_RA_RB(a);
	if (ft_strcmp("RB", move) == 0)
		ft_RA_RB(b);
	if (ft_strcmp("RR", move) == 0)
		ft_RR(a, b);
	if (ft_strcmp("RRA", move) == 0)
		ft_RRA_RRB(a);
	if (ft_strcmp("RRB", move) == 0)
		ft_RRA_RRB(b);
	if (ft_strcmp("RRR", move) == 0)
		ft_RRR(a, b);
}

int			assaign_weight(t_node *node)
{
	t_list	a_copy;
	t_list	b_copy;
	char	**moves_list;
	size_t	index;

	a_copy = copy_linked_list(node->a);
	b_copy = copy_linked_list(node->b);
	moves_list = move_list(node)
	while(index < node->steps)
	{
		apply_rule(move[index], a_copy, b_copy);
		index++;
	}
	get_weight(uygkyu);
	free(move_list k);
	free(a_copy link list);
	free(b_copy linklist)
	return (1);
}