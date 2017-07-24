/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:12:51 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/07/20 11:17:03 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/*
**	-----------------\
**	structs structure
**	-----------------/
*/

typedef struct		s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_stack
{
	t_list			*front;
	t_list			*back;
}					t_stack;

typedef struct		s_node
{
	int				weight;
	struct s_node	*parent;
	char			*move;
	size_t			steps;
	t_stack			*a;
	t_stack			*b;
}					t_node;

/*
**	-----------------\
**	struct for int arr
**	-----------------/
*/

typedef struct		s_pack
{
	int				*int_arr;
	int				elements;
}					t_pack;

/*
**	in file ps_verify.c
*/

int					verify_dup(char *arg);
int					verify_digits(char *arg);
int					verify_min_max(long num);
int					verify_int(char **arg);
int					arr_stoi(char **arg, t_pack *pack);
int					verify_args(char *arg, t_pack *pack);
int					verify_argc(int argc);

/*
**	-----------------------\
**	functions for link lists
**	-----------------------/
*/

t_list				copy_linked_list(t_list *list);
void				ft_add_elem_front(t_list **top, int value);
t_list				*ft_add_elem_back(t_list **back, int value);
t_stack				*ft_init_stack(int *a, int size);
void				ft_swap(t_stack *s);
t_list				*ft_pop_out_back(t_list **back);
t_list				*ft_pop_out_front(t_list **front);
void				ft_free_list(t_list **list);
t_stack				*ft_create_stack(void);
void				ft_SA_SB(t_stack *a);
void				ft_SS(t_stack *a, t_stack *b);
void				ft_PA_PB(t_stack *from, t_stack *to);
void				ft_free_stack(t_stack *stack);

/*
**	-----------------\
**	functions program
**	-----------------/
*/

char				**move_list(t_node *node);
void				apply_rule(char *move, t_stack *a, t_stack *b);
int					assaign_weight(t_node *node);

#endif
