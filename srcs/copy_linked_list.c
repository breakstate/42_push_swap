#include "push_swap.h"

// this is done wrong, you get t_stack not t_list will need to sort

t_list		*copy_linked_list(t_list *list)
{
	t_list	*new_list;
	t_list	*current;

	if (list == NULL)
		return NULL;
	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->value = list->value;
	new_list->prev = NULL;
	current = new_list;
	list = list->next;
	while(list != NULL) 
	{
		current->next = malloc(sizeof(t_list));
		(current->next)->prev = current;
		current = current->next;
		current->value = list->value;
		list = list->next;
	}
	current->next = NULL;
	return (new_list);
}