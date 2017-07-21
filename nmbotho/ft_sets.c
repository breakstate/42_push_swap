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
             printf("temp = [ %p : rule = %s : weight = %d] next = %p\n", temp, (temp->node)->rule, (temp->node)->weight, next);
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
              //  printf("current = [ %p : rule = %s : weight = %d] next = %p || ", current, (current->node)->rule, (current->node)->weight, next);
               // printf("temp = [ %p : rule = %s : weight = %d] next = %p\n", temp, (temp->node)->rule, (temp->node)->weight, next);
                //printf("current = [ %p : rule = %s : weight = %d] next = %p\n", current, (current->node)->rule, (current->node)->weight, next);
                if(next == NULL)
                {
                    printf("appending to %p", current);
                    current->next = temp;
                    current = NULL;
                }
                else
                    current = next;
            }
            else if(node->weight > (current->node)->weight)
            {
                //printf("current = [ %p : rule = %s : weight = %d] next = %p || ", current, (current->node)->rule, (current->node)->weight, next);
                //printf("temp = [ %p : rule = %s : weight = %d] next = %p\n", temp, (temp->node)->rule, (temp->node)->weight, next);
                current->next = temp;
                temp->next = next;
                current = NULL;
            }
            else
            {
                //printf("current = [ %p : rule = %s : weight = %d] next = %p\n", current, (current->node)->rule, (current->node)->weight, next);
                current = next;
                prev = current;
            }
            printf("%d\n", i);
            i++; 
        }
    }
    else
    {
        *open = temp;
    }
}