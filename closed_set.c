#include "push_swap.h"

t_sets		int_closed_set_node(t_node *node)
{
	t_sets	closed_set_node;
	
	closed_set_node.node = node;
	closed_set_node.next = NULL;
	closed_set_node.prev = NULL;
	closed_set_node.weight = &node->weight;
	return (closed_set_node);
}

t_set		*add_to_front_closed_set(t_set *node, t_set *closed_set)
{
	closed_set->prev = node;
	node->next = closed set;
	return (node)
}