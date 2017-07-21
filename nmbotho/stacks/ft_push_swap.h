#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H
#include <stdlib.h>
#include "ft_forbidden.h"
#define _FRONT 1
#define _BACK 0

typedef struct      s_list
{
    int             value;
    struct s_list   *next;
    struct s_list   *prev;
}                   t_list;


typedef struct  s_stack
{
    t_list          *front;
    t_list          *back;
}                   t_stack;

typedef struct s_node
{
    int             weight;
    struct s_node   *parent;
    t_stack         *a;
    t_stack         *b;
    char            *rule;
    int             steps;
}                   t_node;

typedef struct      s_open
{
    t_node          *node;
    struct s_open   *next;
}                   t_open;

typedef struct      s_close
{
    t_node          *node;
    struct s_close  *next;
}                   t_close;
typedef struct      s_array
{
    int             *array;
    size_t          size;
}                   t_array;

typedef struct  s_sets
{
    t_list  *open;
    t_list  *closed;
    t_list  *solved;
}               t_sets;

void        ft_add_elem(t_list **list, t_list *elem, int front);
t_stack     *ft_init_stack(int *a, int size);
void        ft_swap(t_stack *s);
t_list      *ft_pop_out_back(t_list **back);
t_list      *ft_pop_out_front(t_list **front);
void        ft_free_list(t_list **list);
t_stack     *ft_create_stack();
void        ft_SA_SB(t_stack *a);
void        ft_SS(t_stack *a, t_stack *b);
void        ft_PA_PB(t_stack *from, t_stack *to);
void        ft_free_stack(t_stack *stack);
void        ft_RA_RB(t_stack *a);
void        ft_RRA_RRB(t_stack *a);
void        ft_RR(t_stack *a, t_stack *b);
void        ft_RRR(t_stack *a, t_stack *b);
t_list      *ft_create_elem_back(t_list **back, int value);
void        ft_create_elem_front(t_list **top, int value);
int         ft_calc_weight(t_node *node, t_list *final_state);
t_node      *ft_create_node(t_array *array, t_node *parent, t_list *final, char *rule);
void        ft_add_to_openset(t_open **open, t_node *node);
void        ft_add_to_closedset(t_close **close, t_open *open);
#endif
