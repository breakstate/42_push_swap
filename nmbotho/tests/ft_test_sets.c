#include "../ft_push_swap.h"

void ft_print_nodes(t_open *set)
{   int i = 0;


    while(set && i < 9)
    {
        printf("current = [ %p : rule = %s : weight = %d ], current->next = %p\n", set, (set->node)->rule, (set->node)->weight ,set->next);
        set = set->next;
        i++;
    }
}

int main()
{
    t_open *test;
    t_array *array;

    int arr[5] = {9, 4, 1, 16, 7};
    int sorted[5] = {1, 4, 7, 9, 16};
    array->array = arr;
    array->size = 5;
    test = NULL;
    t_stack *sorted_stack = ft_init_stack(sorted, 5);
    t_node *node0 = ft_create_node(array, NULL, sorted_stack->back, "PB");node0->weight = 2;
    t_node *node1 = ft_create_node(array, node0, sorted_stack->back, "PA");node1->weight = 4;
    t_node *node2 = ft_create_node(array, node0, sorted_stack->back, "SS");node2->weight = 3;
    t_node *node3 = ft_create_node(array, node1, sorted_stack->back, "RA");node3->weight = 2;
    t_node *node4 = ft_create_node(array, node1, sorted_stack->back, "RR");
    ft_add_to_openset(&test, node0);
    ft_add_to_openset(&test, node1);
    ft_add_to_openset(&test, node2);
    ft_add_to_openset(&test, node3);
    ft_add_to_openset(&test, node4);
    ft_print_nodes(test);
    return (0);
}