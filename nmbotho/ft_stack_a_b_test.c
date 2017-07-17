#include "ft_push_swap.h"

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

int main(void)
{
    t_stack *a;
    t_stack *b;
    int arr[5];
    int i;

    i = 0;
    a = NULL;
    b = NULL;
    srand(2);
    while(i < 5)
    {
        arr[i] = rand() % 20;
        printf("array = %d\n", arr[i]);
        i++;
    }
    a = ft_init_stack(arr, 5);
    b = ft_init_stack(arr, 0);
    printf("\n-----------------------\n");
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------PB------------\n");
    ft_PA_PB(a, b);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------PB------------\n");
    ft_PA_PB(a, b);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------SA------------\n");
    ft_SA_SB(a);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------SB------------\n");
    ft_SA_SB(b);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------SS------------\n");
    ft_SS(a, b);
    ft_print_stack_a_n_b(a, b);
    printf("\n----------(-RA-)-----------\n");
    ft_RA_RB(a);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------PB------------\n");
    ft_PA_PB(a, b);
    ft_print_stack_a_n_b(a, b);
    printf("\n---------(-RB-)-----------\n");
    ft_RA_RB(b);
    ft_print_stack_a_n_b(a, b);
    printf("\n---------(-(RR)-)----------\n");
    ft_RR(a, b);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------(RRA)-----------\n");
    ft_RRA_RRB(b);
    ft_print_stack_a_n_b(a, b);
    printf("\n-----------(RRR)-----------\n");
    ft_RRR(a, b);
    ft_print_stack_a_n_b(a, b);
    ft_free_stack(a);
    ft_free_stack(b);
    printf("\n");
    return (0);
}