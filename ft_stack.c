#include "ft_push_swap.h"

void	ft_add_elem_front(t_list **top, int value)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if(elem)
	{
		elem->value = value;
		elem->next = NULL;
		elem->prev = NULL;
	}
	if(*top)
	{
		elem->next = *top;
		(*top)->prev = elem;
		
		*top = elem;
	}
	else
		*top = elem;
}

t_list	*ft_add_elem_back(t_list **back, int value)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if(elem)
	{
		elem->value = value;
		elem->next = NULL;
		elem->prev = NULL;
	}
	if(*back)
	{
		(*back)->next = elem;
		elem->prev = *back;
		*back = elem;
	}
	else
		*back = elem;
	return (elem);
}

t_list  *ft_pop_out_front(t_list **front)
{
	t_list *new_head;
	t_list *old_head;

	old_head = *front;
	new_head = (old_head)->next;
	new_head->prev = NULL; /* head's prev must be NULL */
	old_head->next = NULL;
	*front = new_head; /* point to new head */
	return (old_head);
}

t_list  *ft_pop_out_back(t_list **back)
{
	t_list *new_back;
	t_list *old_back;

	old_back = *back;
	new_back = old_back->prev;
	new_back->next = NULL;
	old_back->prev = NULL;
	*back = new_back;
	return (old_back);
}

t_stack *ft_create_stack(int *a, int size)
{
	t_stack *stack;
	int	 i;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->front = NULL;
	stack->back = NULL;
	ft_add_elem_front(&(stack->front), a[0]);
	stack->back = stack->front;
	i = 1;
	if(stack)
	{
		while(i < size)
		{
			stack->back = ft_add_elem_back(&(stack->back), a[i]);
			i++;
		}
	}
	return (stack);
}