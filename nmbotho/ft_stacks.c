#include "ft_push_swap.h"

t_stack *ft_init_stack(int *a, int size)
{
    t_stack *stack;
    int     i;

    stack = ft_create_stack();
    if(size > 0)
    {
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
    }
    return (stack);
}