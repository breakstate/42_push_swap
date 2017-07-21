#include "../ft_push_swap.h"
void   ft_print_stack_a_n_b(t_stack *stack_a, t_stack *stack_b)
{
    t_list *a;
    t_list *b;

    a = stack_a->front;
    b = stack_b->front;
    while(a || b)
    {
        if(a)
        {
            printf(" | a =  %d |",a->value);
            a = a->next;
        }
        else
            printf(" | a =     |");

        if(b)
        {
            printf(" | b = %d |",b->value);
            b = b->next;
        }
        else
            printf(" | b =    |");
        printf("\n");
    }
}
int main()
{
    t_array *array = (t_array*)malloc(sizeof(t_array));
    int arr[5] = {9, 4, 1, 16, 7};
    int i;

    i = 0;
    int sorted[5] = {1, 4, 7, 9, 16};
    
    t_stack *sorted_stack = ft_init_stack(sorted, 5);
    
    array->array = arr;
    array->size = 5;
    t_node *node = ft_create_node(array, NULL, sorted_stack->back, "SA");
    //ft_print_stack_a_n_b(node->a, node->b);
    printf("no of mathces = %d", node->weight);
    return (0);
}