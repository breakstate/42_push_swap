#include "../push_swap.h"

void    ft_add_to_openset(t_nodelist **open, t_node *node)
{
    t_nodelist *current;
    t_nodelist *prev;
    t_nodelist *next;
    t_nodelist *temp;

    current = *open;
    temp = (t_nodelist*)malloc(sizeof(t_nodelist));
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
                if(next == NULL)
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

void    ft_pop_to_closedset(t_nodelist **closed, t_nodelist **open)
{
    t_nodelist *next;
    t_nodelist *temp;

    if(*open)
    {
        temp = *open;           /* get the first node */
        *open = temp->next;        /* set the head to point to the second node */
        if(*closed)
        {
            temp->next = *closed;   /* point temp to the first node in closed */
            *closed = temp;         /* and then make it the new head */
        }
        else
        {
            temp->next = NULL;
            *closed = temp;
        }
    }
}