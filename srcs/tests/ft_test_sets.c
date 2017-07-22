#include "../../push_swap.h"

void ft_print_nodes(t_nodelist *set)
{   
    int i = 0;
    while(set && i < 9)
    {
        printf("current = [ %p : rule = %s : weight = %d ], current->next = %p\n", set, (set->node)->rule, (set->node)->weight ,set->next);
        set = set->next;
        i++;
    }
}

int main()
{
    t_nodelist *open = (t_nodelist*)malloc(sizeof(t_nodelist));
    t_nodelist *closed = (t_nodelist*)malloc(sizeof(t_nodelist));
    t_pack *array = (t_pack*)malloc(sizeof(t_pack));

    int *arr = (int*)malloc(sizeof(int) * 5);
    arr[0] = 9;
    arr[1] = 4;
    arr[2] = 1;
    arr[3] = 16;
    arr[4] = 7;
    
    int *sorted = (int*)malloc(sizeof(int) * 5);
    sorted[0] = 1;
    sorted[1] = 4;
    sorted[2] = 7;
    sorted[3] = 9;
    sorted[4] = 16;
    array->array = arr;
    array->size = 5;
    open = NULL;
    closed = NULL;
    t_stack *sorted_stack = ft_init_stack(sorted, 5);
    t_node *node0 = ft_create_node(array, NULL, sorted_stack->back, "PB");
    t_node *node1 = ft_create_node(array, node0, sorted_stack->back, "PA");
    t_node *node2 = ft_create_node(array, node0, sorted_stack->back, "SS");
    t_node *node3 = ft_create_node(array, node1, sorted_stack->back, "RA");
    t_node *node4 = ft_create_node(array, node1, sorted_stack->back, "RR");
    ft_add_to_openset(&open, node0);
    ft_add_to_openset(&open, node1);
    ft_add_to_openset(&open, node2);
    ft_add_to_openset(&open, node3);
    ft_add_to_openset(&open, node4);
    printf("------------------------current openset ----------------\n");
    ft_print_nodes(open);
    printf("poping to closed set ........\n");
    ft_pop_to_closedset(&closed, &open);
    printf("poping to closed set ........\n");
    ft_pop_to_closedset(&closed, &open);
    printf("poping to closed set ........\n");
    ft_pop_to_closedset(&closed, &open);
    printf("------------------------current openset ----------------\n");
    ft_print_nodes(open);
    printf("------------------------current closedset ----------------\n");
    ft_print_nodes(closed);
    return (0);
}
