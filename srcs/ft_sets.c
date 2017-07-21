#include "ft_push_swap.h"

void    ft_add_to_openset(t_open **open, t_node *node)
{
    t_open *current;
    t_open *prev;
    t_open *next;
    t_open *temp;

    current = *open;
    temp = (t_open*)malloc(sizeof(t_open));
    temp->node = node;
    temp->next = NULL;
    if(*open)
    {
        while(current)
        {
            //printf("current  rule = %s with addr = %p\n", (temp->node)->rule, temp);
            next = current->next;
            if((current->node)->weight > node->weight) /* Finds something its smaller than than, and goes on top of it */
            {
                printf("current  rule = %s with addr = %p\n", (temp->node)->rule, temp);
                if(prev)
                {
                    temp->next = current;
                    prev->next = temp;
                }
                else
                {
                    temp->next = current;
                    *open = temp;
                }
                current = NULL;
            }
            else
            {
                current = current->next;
                prev = current;
            }
        }
    }
    else
        *open = temp;
}