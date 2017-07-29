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
# include <libft.h>
# define _FRONT 1
# define _BACK 0

typedef long long t_ll;
typedef unsigned long long t_ull;

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
	double			weight;
	struct s_node	*parent;
<<<<<<< HEAD
	char			*move;
	size_t			steps;
	t_stack			*a;
	t_stack			*b;
}					t_node;

=======
	t_stack			*a;
	t_stack			*b;
	char			*rule;
	int				steps;
}					t_node;

typedef struct		s_nodelist
{
	t_node				*node;
	struct s_nodelist	*next;
}					t_nodelist;

>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219
/*
**	-----------------\
**	struct for int arr
**	-----------------/
*/

typedef struct		s_pack
{
	int				*array;
	int				size;
}					t_pack;
<<<<<<< HEAD
=======

<<<<<<< HEAD
>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219

=======
>>>>>>> final
/*
**	in file ps_verify.c
*/

<<<<<<< HEAD
int					verify_dup(char *arg);
int					verify_digits(char *arg);
int					verify_min_max(long num);
int					verify_int(char **arg);
int					arr_stoi(char **arg, t_pack *pack);
int					verify_args(char *arg, t_pack *pack);
int					verify_argc(int argc);
=======
int				verify_dup(char *arg);
int				verify_digits(char *arg);
int				verify_min_max(long num);
int				verify_int(char **arg);
int				arr_stoi(char **arg, t_pack *pack);

/*
** in what file?
*/
int				verify_args(char *arg, t_pack *pack);
int				verify_argc(int argc);
>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219

/*
**	-----------------------\
**	functions for link lists
**	-----------------------/
*/

<<<<<<< HEAD
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
=======
t_list			*copy_linked_list(t_list *list);
t_stack			*ft_init_stack(int *a, int size);
t_list			*ft_pop_out_back(t_list **back);
t_list			*ft_pop_out_front(t_list **front);
void			ft_free_list(t_list **list);
t_stack			*ft_create_stack(void);
t_list			*ft_create_elem_back(t_list **back, int value);
void			ft_create_elem_front(t_list **top, int value);
t_node			*ft_create_node(t_pack *pack, t_node *parent, t_pack *final, char *rule);
void			ft_add_to_openset(t_nodelist **open, t_node *node);
void			ft_pop_to_closedset(t_nodelist **closed, t_nodelist **open);
void			ft_free_stack(t_stack *stack);
void			ft_add_elem(t_list **list, t_list *elem, int front);


/*
**	-------------------------\
**	functions that apply rules
**	-------------------------/
*/

void			ft_SA_SB(t_stack *a);
void			ft_SS(t_stack *a, t_stack *b);
void			ft_PA_PB(t_stack *from, t_stack *to);
void			ft_RA_RB(t_stack *a);
void			ft_RRA_RRB(t_stack *a);
void			ft_RR(t_stack *a, t_stack *b);
void			ft_RRR(t_stack *a, t_stack *b);
>>>>>>> 3a965b6b1ea70ece59508dd2cda78e31af81d219

/*
**	-------------------------\
**	jerome functions
**	-------------------------/
*/

char		**move_list(t_node *node);
void		a_star(t_pack *pack);
int			expand(t_node *node, t_nodelist **open,
					t_pack	*final_state, t_pack *pack);
void		expand_open_set(t_nodelist **open, t_pack *final_state,
				t_pack *pack, t_stack *stack_a);
char		**create_list_of_all_moves(void);
void		sort_arr(int **arr, int size);
double		calc_weight(t_node *node, t_pack *final, t_pack *pack);
void		print_move_list(t_node *node);
char		**moves_to_current(t_node *node);
void		apply_rule(t_stack **a, t_stack **b, char *rule);
int			useless_rule(t_node *node, char *move);

#endif