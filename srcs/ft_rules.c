#include "../push_swap.h"

/* SA / SB */

void    ft_SA_SB(t_stack *a)
{
    t_list *b;
    if(a->front)
    {
        if(a->front->next)
        {
            b = a->front->next; /* store b, so you can use it to access c, B IS ALSO SOON TO BE FIRST */
            a->front->prev = b; /* since a will no longer be first, point it to what was second (this case b)*/
            a->front->next = b->next; /* use b to access c which is the third elemnt */
            b->prev = NULL; /*the first element cant have a prev right? */
            b->next = a->front; /* again since b is to be first and a is to be second, then its next should be what was first */
            a->front = b; /* WE FINALLY CROWN B AS NEW KING */
        }
    }
}

/* SS */

void    ft_SS(t_stack *a, t_stack *b)
{
    ft_SA_SB(a);
    ft_SA_SB(b);
}

/* PA */

void    ft_PA_PB(t_stack *from, t_stack *to)
{
    t_list *elem;

    if(from->front)
    {
        elem = ft_pop_out_front(&(from->front));
        ft_add_elem(&(to->front), elem, _FRONT);
        if(to->back == NULL)
            to->back = to->front;
    }
}

/* RA RB */

void    ft_RA_RB(t_stack *a)
{
    t_list *elem;

    if(a->front)
    {
        elem = ft_pop_out_front(&(a->front));
        if(a->back == a->front)
        {
            (a->front)->next = elem;
            elem->prev = a->front;
            elem->next = NULL;
            a->back = elem;
        }
        else
            ft_add_elem(&(a->back), elem, _BACK);
    }
}
void    ft_RRA_RRB(t_stack *a)
{
    t_list *elem;

    if(a->front)
    {
        elem = ft_pop_out_back(&(a->back));
        if(a->back == a->front)
        {
            elem->next = a->front;
            (a->front)->prev = elem;
            a->front = elem;
        }
        else
            ft_add_elem(&(a->front), elem, _FRONT);
    }
}
/* RR */

void    ft_RR(t_stack *a, t_stack *b)
{
    ft_RA_RB(a);
    ft_RA_RB(b);
}

void    ft_RRR(t_stack *a, t_stack *b)
{
    ft_RRA_RRB(a);
    ft_RRA_RRB(b);
}
