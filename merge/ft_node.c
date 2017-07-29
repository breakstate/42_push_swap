#include "./ft_push_swap.h"

t_node *ft_create_node(t_stack *pack, t_node *parent, t_list *final, char *rule)	//PASSED
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
	node->rule = rule;
	node->a = parent->a;
	node->b = parent->b;
	node->parent = parent;
	if(parent)
		node->steps = (parent->steps + 1);
	else
		node->steps = 0;
	node->weight = ft_calc_weight(node, final, pack);
	return (node);
}
/*
int	 ft_calc_weight(t_node *node, t_list *final) //PASSED
{
	t_list *a;
	t_list *b;
	//copy stack a and b then apply rule to it
	// look at apply rule and copy linked list
	a = (node->a)->back;
	b = (node->b)->front;
	int count;
	count = 0;
	while(final)
	{
		if(a)
		{	
			//printf("got here with a = %d and finale->value = %d\n", a->value, final->value);
			if(final->value != a->value)
				count = count + 2;
			a = a->prev;
		}
		else if(b)
		{
			//printf("got here with b = %d and finale->value = %d\n", b->value, final->value);
			if(final->value == b->value)
				count = count + 1;
			else
				count = count + 3;
			b = b->next;
		}
		final = final->prev;
	}
	return (count + (node->steps));
}
*/
int	 ft_calc_weight(t_node *node, t_list *final, t_stack *pack)
{
	t_stack	*stack_a;
	t_list *a;
	t_list *b;
	t_list	*final_current;

	stack_a = ft_create_stack(pack->int_arr, pack->elements)
	
	a = stack_a->front;
	b = (node->b)->back;
	final_current = final;
	int count;
	count = 0;
	while(final_current)
	{
		if(b)
		{
			//printf("got here with b = %d and finale->value = %d\n", b->value, final->value);
			if(final_current->value == b->value)
				count = count + 1;
			else
				count = count + 3;
			b = b->prev;
		}
		else if(a)
		{	
			//printf("got here with a = %d and finale->value = %d\n", a->value, final->value);
			if(final->value != a->value)
				count = count + 2;
			a = a->next;
		}
		if (final->next)
			final = final->next;
		else
			break ;
	}
	return (count + (node->steps));
}