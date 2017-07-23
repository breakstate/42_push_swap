#include "push_swap.h"
#include <stdio.h>

//		ps_main.c
//		verify_controller.c
//		verify.c
//		a_star.c
//		ft_mem_manager.c
//		ft_linkedlists.c
//		ft_stacks.c
//		move_list.c
//		ft_sets.c
//		list_of_moves.c
//		ft_node.c
//		apply_rule.c
//		ft_rules.c

/*
**------------------------------->in file ps_main.c<----------------------------
*/
int		main(int argc, char **argv)
{
	t_pack	pack;
	int		i;

	i = 0;
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
//	ft_nhlaka(pack.int_arr, pack.elements);//handoff to Nhlaka
	a_star(&pack);
 	while (i < pack.size)
		printf("---> %d\n", pack.array[i++]);
	return (0);
}

/*
** ---------------------->in file verify_controller.c<--------------------------
*/
int			verify_args(char *arg, t_pack *pack)
{
	char	**split_args;

	if (!(verify_digits(arg) && arg[0] != '\0'))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	split_args = ft_strsplit(arg, ' ');
	if (!(verify_int(split_args) && split_args[0] != '\0'))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (arr_stoi(split_args, pack));
}

int			verify_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2); //in libft.h
		return (0);
	}
	return (1);
}

/*
** ---------------------------->in file verify.c<-------------------------------
*/
int			verify_digits(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i]) || ft_isspace(arg[i])))
		{
			if (arg[0] == '-' && ft_isdigit(arg[1]))
				;
			else if (!(arg[i] == '-' && ((ft_isdigit(arg[i + 1]))) &&
				((arg[i - 1] == ' '))))
				return (0);
		}
		i++;
	}
	return (verify_dup(arg));
}

/*
**	verify_dup()
**	returns 1 if verfied no duplicates
**	returns 0 if duplicates detected
*/

int			verify_dup(char *arg)
{
	int		i;
	int		j;
	int		pos;
	char	**arr;

	arr = ft_strsplit(arg, ' ');
	i = 0;
	j = 1;
	while (arr[i])
	{
		pos = i;
		while (arr[i + j])
		{
			if (ft_strcmp(arr[i], arr[i + j]) != 0)
				j++;
			else
				return (0);
		}
		free(arr[i]);
		j = 1;
		i = pos + 1;
	}
	return (1);
}

/*
**	verify_int()
**	returns 1 if verified all elements fit into int
**	returns 0 if element > int detected
*/

int			verify_min_max(long num)
{
	int		int_high;
	int		int_low;

	int_high = 2147483647;
	int_low = -2147483648;
	if (num < int_low || num > int_high)
		return (0);
	return (1);
}

int			verify_int(char **arg)
{
	int		sign;
	int		i;
	int		j;
	long	result;

	sign = 1;
	i = 0;
	while (arg[i])
	{
		j = 0;
		result = 0;
		if (arg[i][j] == '-')
			sign = -1;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j] != '\0')
			result = ((result * 10) + (arg[i][j++] - 48));
		result = result * sign;
		if (!(verify_min_max(result)))
			return (0);
		i++;
	}
	return (1);
}

/*
**	takes in a 2d char array and converts to int array
**	assumes checks have been done prior
**	arg_len can be determined in another function or within arr_stoi()
*/

int			arr_stoi(char **arg, t_pack *pack)
{
	int		i;

	i = 0;
	pack->size = 0;
	while (arg[pack->size])
		pack->size++;
	pack->array = (int *)ft_memalloc(sizeof(int) * pack->size);
	if (pack->array == NULL)
	{
		return (0);
	}
	while (arg[i])
	{
		pack->array[i] = ft_atoi(arg[i]);
		i++;
	}
	return (1);
}

/*
**	notes
** 	0 is bad, 1 is good, can be reversed if preferred
*/

/*
** ---------------------------->in file a_star.c<-------------------------------
*/

/* sort out later
int			is_rule_rev(char *parent_rule, char *rule_to_make)
{
	if (!ft_strcmp("SS", rule_to_make) &&
			(!ft_strcmp("SB", parent_rule) || !ft_strcmp("SA", parent_rule)))
		return TRUE;
	if (!ft_strcmp("SB", rule_to_make) && !ft_strcmp("SB", parent_rule))
		return TRUE;
	if (!ft_strcmp("SA", rule_to_make) && !ft_strcmp("SA", parent_rule))
		ft_SS(a, b);
	if (ft_strcmp("PA", parent_rule) == 0)
		ft_PA_PB(b, a);
	if (ft_strcmp("PB", parent_rule) == 0)
		ft_PA_PB(a, b);
	if (ft_strcmp("RA", parent_rule) == 0)
		ft_RA_RB(a);
	if (ft_strcmp("RB", parent_rule) == 0)
		ft_RA_RB(b);
	if (ft_strcmp("RR", parent_rule) == 0)
		ft_RR(a, b);
	if (ft_strcmp("RRA", parent_rule) == 0)
		ft_RRA_RRB(a);
	if (ft_strcmp("RRB", parent_rule) == 0)
		ft_RRA_RRB(b);
	if (ft_strcmp("RRR", parent_rule) == 0)
		ft_RRR(a, b);
	else
		return (FALSE);
}*/

int			expand(t_node *node, t_nodelist **open,
					t_pack	*final_state, t_pack *pack)
{
	int		i;
	char	**move_list;
	t_node	*current;

	if (node->weight == node->steps)
		return (FALSE);
	i = -1;
	move_list = list_of_moves();
	while (++i <= 10)
	{
		//if (node_rev(node->rule, move_list[i]) == TRUE)
		//	continue ;
		current = ft_create_node(pack, node, final_state, move_list[i]);
		ft_add_to_openset(open, current);
	}
//	ft_free_2d_arr((void ***)&move_list, 11);
	return (TRUE);
}

void		put_move_list(t_node *node)
{

}

void		expand_open_set(t_nodelist **open, t_pack *final_state,
				t_pack *pack, t_stack *stack_a)
{
	t_nodelist	*closed;

	closed = NULL;
	while (*open)
	{
		if (expand((*open)->node, open, final_state, pack) == FALSE)
		{
			put_move_list((*open)->node);
			break ;
		}
		ft_pop_to_closedset(&closed, open);
	}
//	free(open);
//	free(closed);
}

t_pack			*create_final_state(t_pack *pack)
{
	t_pack	*final_state;
	int		i;

	final_state = (t_pack *)malloc(sizeof(t_pack));
	if (final_state)
	{
		final_state->array = (int *)malloc(sizeof(int) * (pack->size));
		if(final_state->array)
		{
			i = 0;
			while (i < pack->size)
			{
				(final_state->array)[i] = (pack->array)[i];
				i++;
			}
			final_state->size = pack->size;
		}
	}
	sort_arr(&(final_state->array), (final_state->size));
	return (final_state);
}

void		a_star(t_pack *pack)
{
	t_stack		*stack_a;
	t_pack		*final_state;
	t_node		*start;
	t_nodelist	*open;

	stack_a = ft_init_stack(pack->array, pack->size);
	final_state = create_final_state(pack);
	start = ft_create_node(pack, NULL, final_state, NULL);
	open = NULL;
	ft_add_to_openset(&open, start);
	expand_open_set(&open, final_state, pack, stack_a);
}

/*
** ------------------------>in file ft_mem_manager.c<---------------------------
*/
#include "../push_swap.h"

void ft_free_list(t_list **list)
{
	t_list *next;
	
	if(*list)
	{
		while(*list)
		{
			next = (*list)->next;
			free(*list);
			*list = next;
		}
		free(*list);
	}
}

void ft_free_stack(t_stack *stack)
{
	ft_free_list(&(stack->front));
	stack->front = NULL;
	stack->back = NULL;
	free(stack);
}

t_stack *ft_create_stack()
{
	t_stack *stack;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack)
	{
		stack->front = NULL;
		stack->back = NULL;
	}
	return (stack);
}

t_list *ft_create_elem(int value)
{
	t_list *link;

	link = (t_list*)malloc(sizeof(t_list));
	link->value = value;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

/*
** ---------------------->in file ft_linkedlists.c<-----------------------------
*/
void	ft_create_elem_front(t_list **top, int value)
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

t_list	*ft_create_elem_back(t_list **back, int value)
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

void	ft_add_elem(t_list **list, t_list *elem, int front)
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
		//	printf("elem = %p, value = %d\n", elem, elem->value);
	//	 printf("*list = %p, value = %d\n", *list, (*list)->value);
		*list = elem;
	}
	else if(elem)
		*list = elem;
}

t_list	*ft_pop_out_front(t_list **front)
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

t_list	*ft_pop_out_back(t_list **back)
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

/*
** ---------------------->in file ft_stacks.c<-----------------------------
*/
t_stack		*ft_init_stack(int *a, int size)
{
	t_stack	*stack;
	int		i;

	stack = ft_create_stack();
	if(size > 0)
	{
		if(stack)
		{
			ft_create_elem_front(&(stack->front), a[0]);
			stack->back = stack->front;
			i = 1;
			while(i < size)
			{
				stack->back = ft_create_elem_back(&(stack->back), a[i]);
				i++;
			}
		}
	}
	return (stack);
}

/*
** ------------------------->in file move_list.c<-------------------------------
*/
char		**move_list(t_node *node)
{
	char	**moves_list;
	size_t	index;
	t_node	*current;

	moves_list = (char **)malloc(sizeof(char *) * (node->steps + 1));
	if (moves_list)
	{
		current = node;
		moves_list[node->steps] = (char *)malloc(sizeof(char) * 1);
		moves_list[node->steps] = '\0';
		index = node->steps - 1;
		while ((index <= 0) && (current != NULL) && (current->rule != NULL))
		{
			moves_list[index] = ft_strdup((const char *)current->rule);
			index--;
			current = node->parent;
		}
	}
	return (moves_list);
}

/*
** -------------------------->in file ft_sets.c<--------------------------------
*/
#include "../push_swap.h"

void	ft_add_to_openset(t_nodelist **open, t_node *node)
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
				else //if((next->node)->weight > node->weight)
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

void	ft_pop_to_closedset(t_nodelist **closed, t_nodelist **open)
{
	t_nodelist *next;
	t_nodelist *temp;

	if(*open)
	{
		temp = *open;			/* get the first node */
		*open = temp->next;		/* set the head to point to the second node */
		if(*closed)
		{
			temp->next = *closed;	/* point temp to the first node in closed */
			*closed = temp;		 /* and then make it the new head */
		}
		else
		{
			temp->next = NULL;
			*closed = temp;
		}
	}
}

/*
** ----------------------->in file list_of_moves.c<-----------------------------
*/
static void	assaign_rule_list(char	***list_of_moves)
{
	if ((*list_of_moves)[0])
		(*list_of_moves)[0] = "SA";
	if ((*list_of_moves)[1])
		(*list_of_moves)[1] = "SB";
	if ((*list_of_moves)[2])
		(*list_of_moves)[2] = "SS";
	if ((*list_of_moves)[3])
		(*list_of_moves)[3] = "PA";
	if ((*list_of_moves)[4])
		(*list_of_moves)[4] = "PB";
	if ((*list_of_moves)[5])
		(*list_of_moves)[5] = "RA";
	if ((*list_of_moves)[6])
		(*list_of_moves)[6] = "RB";
	if ((*list_of_moves)[7])
		(*list_of_moves)[7] = "RR";
	if ((*list_of_moves)[8])
		(*list_of_moves)[8] = "RRA";
	if ((*list_of_moves)[9])
		(*list_of_moves)[9] = "RRB";
	if ((*list_of_moves)[10])
		(*list_of_moves)[10] = "RRR";
}

char		**list_of_moves(void)
{
	char	**list_of_moves;
	int		index;

	list_of_moves = (char **)malloc(sizeof(char *) * 11);
	if (list_of_moves)
	{
		index = -1;
		while (++index <= 10)
			list_of_moves[index] = ft_memalloc(sizeof(char) * 4);
		assaign_rule_list(&list_of_moves);
	}
	return (list_of_moves);
}

/*
** ----------------------->in file ft_node.c<-----------------------------
*/
t_node	*ft_create_node(t_pack *pack, t_node *parent, t_pack *final, char *rule)	//PASSED
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
	node->rule = rule;
	node->parent = parent;
	if(parent)
	{
		node->a = parent->a;
		node->b = parent->b;
		node->steps = (parent->steps + 1);
	}
	else
	{
		node->steps = 0;
		node->a = ft_init_stack(pack->array, pack->size);
		node->b = ft_init_stack(pack->array, 0);
	}
	node->weight = ft_calc_weight(node, final, pack);
	return (node);
}

int		ft_calc_weight(t_node *node, t_pack *final, t_pack *pack)
{
	return (1);
}
/*
int	 ft_calc_weight(t_node *node, t_list *final) //PASSED
{
	t_list *a;
	t_list *b;
	//copy stack a and b then apply rule to it
	// look at apply rule and copy linked list
	a = (node->a)->back;
	b = (node->b)->front;
	int count;
	count = 0;
	while(final)
	{
		if(a)
		{	
			//printf("got here with a = %d and finale->value = %d\n", a->value, final->value);
			if(final->value != a->value)
				count = count + 2;
			a = a->prev;
		}
		else if(b)
		{
			//printf("got here with b = %d and finale->value = %d\n", b->value, final->value);
			if(final->value == b->value)
				count = count + 1;
			else
				count = count + 3;
			b = b->next;
		}
		final = final->prev;
	}
	return (count + (node->steps));
}
*//*
int		ft_calc_weight(t_node *node, t_list *final, t_pack *pack)
{
	t_stack	*stack_a;
	t_list *a;
	t_list *b;
	t_list	*final_current;

	stack_a = ft_init_stack(pack->array, pack->size);
	
	a = stack_a->front;
	b = (node->b)->back;
	final_current = final;
	int count;
	count = 0;
	while(final_current)
	{
		if(b)
		{
			//printf("got here with b = %d and finale->value = %d\n", b->value, final->value);
			if(final_current->value == b->value)
				count = count + 1;
			else
				count = count + 3;
			b = b->prev;
		}
		else if(a)
		{	
			//printf("got here with a = %d and finale->value = %d\n", a->value, final->value);
			if(final->value != a->value)
				count = count + 2;
			a = a->next;
		}
		if (final->next)
			final = final->next;
		else
			break ;
	}
	return (count + (node->steps));
}*/

/*
** ------------------------>in file apply_rule.c<-------------------------------
*/
void		apply_rule(t_node *node, char *rule)
{
	t_stack *a;
	t_stack *b;

	a = node->a;
	b = node->b;
	if (ft_strcmp("SA", rule) == 0)
		ft_SA_SB(a);
	if (ft_strcmp("SB", rule) == 0)
		ft_SA_SB(b);
	if (ft_strcmp("SS", rule) == 0)
		ft_SS(a, b);
	if (ft_strcmp("PA", rule) == 0)
		ft_PA_PB(b, a);
	if (ft_strcmp("PB", rule) == 0)
		ft_PA_PB(a, b);
	if (ft_strcmp("RA", rule) == 0)
		ft_RA_RB(a);
	if (ft_strcmp("RB", rule) == 0)
		ft_RA_RB(b);
	if (ft_strcmp("RR", rule) == 0)
		ft_RR(a, b);
	if (ft_strcmp("RRA", rule) == 0)
		ft_RRA_RRB(a);
	if (ft_strcmp("RRB", rule) == 0)
		ft_RRA_RRB(b);
	if (ft_strcmp("RRR", rule) == 0)
		ft_RRR(a, b);
}

/*
** ------------------------>in file ft_rules.c<---------------------------------
*/
void	ft_SA_SB(t_stack *a)
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

void	ft_SS(t_stack *a, t_stack *b)
{
	ft_SA_SB(a);
	ft_SA_SB(b);
}

/* PA */

void	ft_PA_PB(t_stack *from, t_stack *to)
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

void	ft_RA_RB(t_stack *a)
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
void	ft_RRA_RRB(t_stack *a)
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

void	ft_RR(t_stack *a, t_stack *b)
{
	ft_RA_RB(a);
	ft_RA_RB(b);
}

void	ft_RRR(t_stack *a, t_stack *b)
{
	ft_RRA_RRB(a);
	ft_RRA_RRB(b);
}

/*
** ------------------------>in file sort_arr.c<---------------------------------
*/

void	sort_arr(int **arr, int size)
{
	int		temp;
	int		flag;
	int		i;

	i = 0;
	temp = 0;
	flag = 0;
	while (i < size - 1)
	{
		if ((*arr)[i] > (*arr)[i + 1])
		{
			temp = (*arr)[i];
			(*arr)[i] = (*arr)[i + 1];
			(*arr)[i + 1] = temp;
			flag = 1;
		}
		i++;
		if (i == size - 1 && flag == 1)
		{
			i = 0;
			flag = 0;
		}
	}
}