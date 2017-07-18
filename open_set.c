#include "push_swap.h"

t_sets		int_openset_node(t_node *node)
{
	t_sets	open_set_node;

	open_set_node->node = node;
	open_set_node->next = NULL;
	open_set_node->prev = NULL;
	open_set_node->weight = &node->weight;
	return (open_set_node);
}

void		add_openset_node(t_node *node, t_sets open_set)
{
	int		index;

	index = 0;
	int_openset_node(*node)
	while ()
}

void		open_set(t_node node)
{
	t_sets	open_set;
	open_set = int_openset(node)

}