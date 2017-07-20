#include "./ft_push_swap.h"

t_node *ft_create_node(t_array *array, t_node *parent, t_list *final, char *rule)  //PASSED
{
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    node->rule = rule;
    node->a = ft_init_stack(array->array, array->size);
    node->b = ft_init_stack(array->array, 0);
    node->parent = parent;
    if(parent)
        node->steps = (parent->steps + 1);
    else
        node->steps = 0;
    node->weight = ft_calc_weight(node, final);
    return (node);
}

int     ft_calc_weight(t_node *node, t_list *final) //PASSED
{
    t_list *a;
    t_list *b;
    a = (node->a)->back;
    b = (node->b)->front;
    int count;
    count = 0;
    while(final)
    {
        if(a)
        {    
            //printf("got here with a = %d and finale->value = %d\n", a->value, final->value);
            if(final->value == a->value)
                count++;
            a = a->prev;
        }
        else if(b)
        {
            //printf("got here with b = %d and finale->value = %d\n", b->value, final->value);
            if(final->value == b->value)
                count++;
            b = b->next;
        }
        final = final->prev;
    }
    return (count);
}