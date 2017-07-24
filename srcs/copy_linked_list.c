#include "push_swap.h"

<<<<<<< HEAD:copy_linked_list.c
t_stack		*copy_linked_stack(t_stack *stack)
{
	t_stack	*new_stack;
	t_list	*to
	t_list	*from
=======
// this is done wrong, you get t_stack not t_list will need to sort

t_list		*copy_linked_list(t_list *list)
{
	t_list	*new_list;
	t_list	*current;
>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219:srcs/copy_linked_list.c

	if (stack == NULL)
		return NULL;
	new_stack->front = (t_list *)malloc(sizeof(t_list));
	new_stack->back = (t_list *)malloc(sizeof(t_list));
	if (stack->front != NULL)
	{
<<<<<<< HEAD:copy_linked_list.c
		
	}
	stack
/*	new_stack->value = stack->value;
	new_stack->prev = NULL;
	current = new_stack;
	stack = stack->next;
	while(stack != NULL) 
	{
		current->next = malloc(sizeof(t_stack);
		(current->next)->prev = current;
		current = current->next;
		current->value = stack->value);
		stack = stack->next;
	}
	current->next = NULL;
*/	return (&new_stack);
}
=======
		current->next = malloc(sizeof(t_list));
		(current->next)->prev = current;
		current = current->next;
		current->value = list->value;
		list = list->next;
	}
	current->next = NULL;
	return (new_list);
}
>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219:srcs/copy_linked_list.c
