#include "push_swap.h"

//this is more of a templeat at the moment


/* sort out later
int			is_rule_rev(char *parent_rule, char *rule_to_make)
{
	if (!ft_strcmp("SS", rule_to_make) &&
			(!ft_strcmp("SB", parent_rule) || !ft_strcmp("SA", parent_rule)))
		return TRUE;
	if (!ft_strcmp("SB", rule_to_make) && !ft_strcmp("SB", parent_rule))
		return TRUE;
	if (!ft_strcmp("SA", rule_to_make) && !ft_strcmp("SA", parent_rule))
		ft_SS(a, b);
	if (ft_strcmp("PA", parent_rule) == 0)
		ft_PA_PB(b, a);
	if (ft_strcmp("PB", parent_rule) == 0)
		ft_PA_PB(a, b);
	if (ft_strcmp("RA", parent_rule) == 0)
		ft_RA_RB(a);
	if (ft_strcmp("RB", parent_rule) == 0)
		ft_RA_RB(b);
	if (ft_strcmp("RR", parent_rule) == 0)
		ft_RR(a, b);
	if (ft_strcmp("RRA", parent_rule) == 0)
		ft_RRA_RRB(a);
	if (ft_strcmp("RRB", parent_rule) == 0)
		ft_RRA_RRB(b);
	if (ft_strcmp("RRR", parent_rule) == 0)
		ft_RRR(a, b);
	else
		return (FALSE);
}*/

int			expand (t_node *node, t_open *open,
					t_list	*final_state, t_pack *pack)
{
	int		i;
	char	**move_list;
	t_node	*current;

	if (node->weight == node->steps)
		return (FALSE);
	i = -1;
	move_list = list_of_moves();
	while (++i <= 10)
	{
		//if (node_rev(node->rule, move_list[i]) == TRUE)
		//	continue ;
		current = ft_create_node(pack, node, final_state, move_list[i]);
		ft_add_to_openset(&open, current);
	}
	ft_free_2d_arr((void ***)&move_list, 11);
	return (TRUE);
}

void		expand_open_set(t_open *open, t_list *final_state,
				t_pack *pack, t_stack *stack_a)
{
	t_closed	*closed;
	t_open		*temp;

	closed = NULL;
	while (*open)
	{
		temp = (*open);
		if (expand (open->node, open, *final_state, pack) == FALSE)
			break ;
		temp->next == NULL;
		add_to_closed_set(&closed, temp)
	}
	free(open);
	free(closed);
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