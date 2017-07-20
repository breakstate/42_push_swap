#include "ft_push_swap.h"

void ft_free_list(t_list **list)
{
    t_list *next;
    
    if(*list)
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

void ft_free_stack(t_stack *stack)
{
    ft_free_list(&(stack->front));
    stack->front = NULL;
    stack->back = NULL;
    free(stack);
}

t_stack *ft_create_stack()
{
    t_stack *stack;
    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->front = NULL;
    stack->back = NULL;
    return (stack);
}

t_list *ft_create_elem(int value)
{
    t_list *link;

    link = (t_list*)malloc(sizeof(t_list));
    link->value = value;
    link->next = NULL;
    link->prev = NULL;
    return (link);
}