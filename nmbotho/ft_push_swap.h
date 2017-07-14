#include <stdlib.h>
#include "ft_forbidden.h"
typedef struct  s_list
{
    int             value;
    struct s_list   *next;
    struct s_list   *prev;
}               t_list;

typedef struct  s_stack
{
    t_list      *front;
    t_list      *back;
}               t_stack;

void        ft_add_elem_front(t_list **top, int value);
t_list      *ft_add_elem_back(t_list **back, int value);
t_stack     *ft_create_stack(int *a, int size);
void        ft_swap(t_stack *s);
t_list      *ft_pop_out_back(t_list **back);
t_list      *ft_pop_out_front(t_list **front);