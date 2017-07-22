#include "../push_swap.h"

void    ft_create_elem_front(t_list **top, int value)
{
    t_list *elem;

    elem = (t_list*)malloc(sizeof(t_list));
    if(elem)
    {
        elem->value = value;
        elem->next = NULL;
        elem->prev = NULL;
    }
    if(*top)
    {
        elem->next = *top;
        (*top)->prev = elem;
        *top = elem;
    }
    else
        *top = elem;
}

t_list    *ft_create_elem_back(t_list **back, int value)
{
    t_list *elem;

    elem = (t_list*)malloc(sizeof(t_list));
    if(elem)
    {
        elem->value = value;
        elem->next = NULL;
        elem->prev = NULL;
    }
    if(*back)
    {
        (*back)->next = elem;
        elem->prev = *back;
        *back = elem;
    }
    else
        *back = elem;
    return (elem);
}

void    ft_add_elem(t_list **list, t_list *elem, int front)
{   
    if(*list && elem)
    {
        //printf("list = %p, list->value = %d\n", *list, (*list)->value);
        if(front)
        {
            (*list)->prev = elem;
            elem->next = *list;
            elem->prev = NULL;
        }
        else
        {
            elem->prev = *list;
            (*list)->next = elem;
            elem->next = NULL;
        }
      //  printf("elem = %p, value = %d\n", elem, elem->value);
   //     printf("*list = %p, value = %d\n", *list, (*list)->value);
        *list = elem;
    }
    else if(elem)
        *list = elem;
}

t_list  *ft_pop_out_front(t_list **front)
{
    t_list *new_head;
    t_list *old_head;

    new_head = NULL;
    old_head = NULL;
    if(*front)
    {  
        old_head = *front;
        if(old_head->next)
        {
            new_head = old_head->next;
            old_head->next = NULL;
            new_head->prev = NULL; /* head's prev must be NULL */ 
        }    
        *front = new_head; /* point to new head */
        return (old_head);
    }
    return (NULL);
}

t_list  *ft_pop_out_back(t_list **back)
{
    t_list *new_back;
    t_list *old_back;

    if(*back)
    {
        old_back = *back;
        new_back = old_back->prev;
        new_back->next = NULL;
        old_back->prev = NULL;
        *back = new_back;
        return (old_back);
    }
    return(NULL);
}
