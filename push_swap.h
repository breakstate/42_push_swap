#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_forbidden.h"
# define _FRONT 1
# define _BACK 0

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
	t_stack			*a;
	t_stack			*b;
	char			*rule;
	int				steps;
}					t_node;

/*
** maybe make one struct
*/

typedef struct		s_open
{
	t_node			*node;
	struct s_open	*next;
}					t_open;

typedef struct		s_close
{
	t_node			*node;
	struct s_closed *next;
}					t_close;


/*
** already exists
*/

typedef struct		s_array
{
	int				*array;
	size_t			size;
}					t_array;

/*
** fix below
*/

typedef struct		s_sets
{
	t_list			*open;
	t_list			*closed;
	t_list			*solved;
}					t_sets;

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

/*
**	-----------------------\
**	functions for link lists
**	-----------------------/
*/

t_list			*copy_linked_list(t_list *list);
void			ft_add_elem_front(t_list **top, int value);
t_list			*ft_add_elem_back(t_list **back, int value);
t_stack			*ft_init_stack(int *a, int size);
t_list			*ft_pop_out_back(t_list **back);
t_list			*ft_pop_out_front(t_list **front);
void			ft_free_list(t_list **list);
t_stack			*ft_create_stack(void);
t_list			*ft_create_elem_back(t_list **back, int value);
void			ft_create_elem_front(t_list **top, int value);
t_node			*ft_create_node(t_array *array, t_node *parent, t_list *final_state, char *rule);
void			ft_add_to_openset(t_open **open, t_node *node);
void			ft_free_stack(t_stack *stack);

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

#endif
