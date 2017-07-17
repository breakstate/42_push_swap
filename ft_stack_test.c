#include "ft_push_swap.h"

void   ft_print_stack_elements(t_stack *stack)
{
	t_list *items;

	items = stack->front;
	if(items)
	{
		while(items)
		{
			printf(" - stack = %d\n", items->value);
			items = items->next;
		}
	}
	else
		printf("list is empty\n");
}

void ft_free_list(t_list **list)
{
	t_list *next;
	
	if(*list) // DO THIS AND YOU SHOULD NEVER HAVE A PROBLEM OF DOUBLE FREE :)
	{
		while(*list)
		{
			next = (*list)->next;
			free(*list);
			*list = next;
		}
		free(*list);
	}
}

int main(void)
{
	t_stack *stack;
	t_list *elem;
	int arr[5];
	int i;

	i = 0;
	stack = NULL;
	srand(2);
	while(i < 5)
	{
		arr[i] = rand() % 20;
		printf("array = %d\n", arr[i]);
		i++;
	}
	stack = ft_create_stack(arr, 5);
	printf("-----------------------\n");
	ft_print_stack_elements(stack);
	printf("-----------------------\n");
	printf("element at stack->front = %d\n", (stack->front)->value);
	printf("element at stack->back = %d\n", (stack->back)->value);
	printf("-----------------------\n");
	printf("----	 swap	----\n");
	ft_swap(stack);
	printf("-----------------------\n");
	ft_print_stack_elements(stack);
	printf("-----------------------\n");
	printf("----	 pop out front	----\n");
	elem = ft_pop_out_front(&(stack->front));
	printf("-----------------------\n");
	ft_print_stack_elements(stack);
	printf("-----------------------\n");
	printf("-----  poped out element = %d  -------\n", elem->value);
	printf("-----------------------\n");
	printf("----	 pop out front	----\n");
	free(elem);
	elem = ft_pop_out_front(&(stack->front));
	printf("-----------------------\n");
	ft_print_stack_elements(stack);
	printf("-----------------------\n");
	printf("-----  poped out element = %d  -------\n", elem->value);
	printf("---------FREEING LIST--------\n"); 
	ft_free_list(&(stack->front));
	free(stack);
	free(elem);
	return (0);
}