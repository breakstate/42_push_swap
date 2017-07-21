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
    prev = NULL;
    next = NULL;
    int i = 0;
    if(*open)
    {
        while(current && i < 10)
        {
            next = current->next;
            if(node->weight < (current->node)->weight)
            {
                if(prev == NULL)
                {
                    temp->next = current;
                    *open = temp;
                }
                else
                {
                    prev->next = temp;
                    temp->next = current;   
                }
                current = NULL;
            }
            else if(node->weight == (current->node)->weight)
            {
                if(next == NULL)
                {
                    current->next = temp;
                    current = NULL;
                }
                else if((next->node)->weight > node->weight)
                {
                    current->next = temp;
                    temp->next = next;
                    current = NULL;
                }
            }
            else if(node->weight > (current->node)->weight)
            {
                current->next = temp;
                temp->next = next;
                current = NULL;
            }
            else
            {
                current = next;
                prev = current;
            }
        }
    }
    else
    {
        *open = temp;
    }
}

