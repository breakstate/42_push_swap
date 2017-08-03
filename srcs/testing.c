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
//	printf("---> hello");
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
//	ft_nhlaka(pack.int_arr, pack.elements);//handoff to Nhlaka
	a_star(&pack);
/*	while (i < pack.size)
		printf("---> %d\n", pack.array[i++]);
*/	return (0); 
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

static int	is_rule_rev(char *parent_rule, char *rule_to_make)
{
	if (rule_to_make && parent_rule)
	{
	if (!ft_strcmp("sa", parent_rule) && 
			(!ft_strcmp("sa", rule_to_make) || !ft_strcmp("ss", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("sb", parent_rule) &&
			(!ft_strcmp("sb", rule_to_make) || !ft_strcmp("ss", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("ss", parent_rule) &&
			(!ft_strcmp("sb", rule_to_make) || !ft_strcmp("ss", rule_to_make) ||
			!ft_strcmp("ss", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("pa", parent_rule) &&
			(!ft_strcmp("pb", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("pb", parent_rule) &&
			(!ft_strcmp("pa", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("ra", parent_rule)
			&& (!ft_strcmp("rra", rule_to_make)
				|| !ft_strcmp("rrr", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("rb", parent_rule)
			&& (!ft_strcmp("rrb", rule_to_make)
			|| !ft_strcmp("rrr", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("rr", parent_rule) &&
			(!ft_strcmp("rra", rule_to_make) || !ft_strcmp("rrb", rule_to_make)
			|| !ft_strcmp("rrr", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("rra", parent_rule) &&
			(!ft_strcmp("ra", rule_to_make) || !ft_strcmp("rr", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("rrb", parent_rule) &&
			(!ft_strcmp("rb", rule_to_make) || !ft_strcmp("rr", rule_to_make)))
		return (TRUE);
	else if (!ft_strcmp("rrr", parent_rule) &&
			(!ft_strcmp("ra", rule_to_make) || !ft_strcmp("rb", rule_to_make)
			|| !ft_strcmp("rr", rule_to_make)))
		return (TRUE);
	}
	else
		return (FALSE);	
}

/*
** in useless_rule if there is nothing in list front and back are the same 
** i.e. NULL
*/

int		useless_rule(t_node *node, char *move)
{
	if ((node->a->front == node->a->back)
			&& ((!ft_strcmp(move, "sa") || !ft_strcmp(move, "ss")
				|| !ft_strcmp(move, "ra") || !ft_strcmp(move, "rra")
				|| !ft_strcmp(move, "rr") || !ft_strcmp(move, "rrr"))))
		return (TRUE);
	if ((node->b->front == node->b->back)
			&& ((!ft_strcmp(move, "sb") || !ft_strcmp(move, "ss")
				|| !ft_strcmp(move, "rb") || !ft_strcmp(move, "rrb")
				|| !ft_strcmp(move, "rr") || !ft_strcmp(move, "rrr"))))
		return (TRUE);
	if ((node->a->front == NULL) && (!ft_strcmp(move, "pb")))
		return (TRUE);
	if ((node->b->front == NULL) && (!ft_strcmp(move, "pa")))
		return (TRUE);
	return (FALSE);
}

int			compare_stack(t_stack *old, t_stack *new)
{
	t_list	*old_current;
	t_list	*new_current;

	if (old == NULL && new == NULL)
		return (0);
	if (old == NULL || new == NULL)
		return (ERROR);
	old_current = old->front;
	new_current = new->front;
	while (old_current != NULL && new_current != NULL)
	{
		if (old_current->value != new_current->value)
			return (old_current->value - new_current->value);
		old_current = old_current->next;
		new_current = new_current->next;
	}
	if (old_current == NULL && new_current == NULL)
		return (0);
	return (1);
}

int			is_current_in_open(t_nodelist **closed, t_node *new_node)
{
	t_nodelist		*current;

	if (*closed == NULL || new_node == NULL)
		return (ERROR);
	if ((*closed)->node == NULL)
		return (ERROR);
	current = *closed;
	while (current != NULL)
	{
		if (current->node == NULL)
			return (ERROR);
		if(compare_stack(current->node->a, new_node->a) == 0)
			if(compare_stack(current->node->b, new_node->b) == 0)
				return (TRUE);
		current = current->next;
	}
	return (FALSE);
	////////////////////////--------------------------------------------------------------------
	
}

int			expand(t_node *node, t_sets *sets,
					t_pack	*final_state, t_pack *pack)
{
	int		i;
	char	**list_of_all_moves;
	t_node	*current;

	if (node->weight <= (double)node->steps)
		return (FALSE);
	i = -1;
	list_of_all_moves = create_list_of_all_moves();
	while (++i <= 10)
	{
		if ((is_rule_rev(node->rule, list_of_all_moves[i]) == TRUE)
				|| (useless_rule(node, list_of_all_moves[i]) == TRUE))
			continue ;
		current = ft_create_node(pack, node, final_state, list_of_all_moves[i]);
		if (is_current_in_open(sets->closed, current) == TRUE)
		{
			//free(current);
			continue ;
		}
		ft_add_to_openset(sets->open, current);
	}
//	ft_free_2d_arr((void ***)&list_of_all_moves, 11); 
	return (TRUE);
}

void		print_move_list(t_node *node)
{
	char	**final_move_list;
	int		index;

	final_move_list = moves_to_current(node);
	if (final_move_list == NULL)
		return ;
	index = 0;
	while (final_move_list[index])
	{
		ft_putendl_fd(final_move_list[index], 2);
		index++;
	}
}

void		test_print(t_node *node)
{
	int i = 0;
	t_list *current;

	current = node->a->front;
	printf ("\n        stack a = [");
	while (current)
	{
		printf("%i ", current->value);
		current = current->next;
	}
	printf("]");
	current = node->b->front;
	printf ("\n        stack b = [");
	while (current)
	{
		printf("%i ", current->value);
		current = current->next;
	}
	printf("]");
}

void		expand_open_set(t_nodelist **open, t_pack *final_state,
				t_pack *pack, t_stack *stack_a)
{
	t_nodelist	*closed;
	t_node		*current;
	t_sets		*sets;
	int			count;

	closed = NULL;
	current = NULL;
	sets = (t_sets*)malloc(sizeof(t_sets));
	if (sets)
	{
		sets->open = open;
		sets->closed = &closed;
	}
	count = 0;
	while (*open)
	{
		printf("\nthe amount of expanded nodes is [%i]", count++);
		current = (*open)->node;
		printf("\n    the wigth of the node is [%lf]", current->weight);
		test_print(current);
		ft_pop_to_closedset(sets->closed, sets->open);
 		if (expand(current, sets, final_state, pack) == FALSE)
		{
			printf("\nthe answer is\n");
			print_move_list(current);
			break ;
		}
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
		//	printf("elem = %p, value = %d\n",long long elem, elem->value);
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
		new_back = (*back)->prev;
		if (new_back)
			new_back->next = NULL;
		if (old_back)
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
char		**moves_to_current(t_node *node)
{
	char	**moves_list;
	int		index;
	t_node	*current;
	if (node)
		if (node->rule)
		{
			moves_list = (char **)malloc(sizeof(char *) * (node->steps + 1));
			if (moves_list)
			{
				current = node;
				moves_list[node->steps] = (char *)malloc(sizeof(char) * 1);
				moves_list[node->steps] = NULL;
				index = node->steps - 1;
				while ((index >= 0) && (current != NULL) 
						&& (current->rule != NULL))
				{
					moves_list[index] = ft_strdup((const char *)current->rule);
					index--;
					current = current->parent;
				}
			}
			return (moves_list);
		}
	return (NULL);
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
	if(*open)
	{
		while(current)
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
					prev = current;
					current = next;
					/*current->next = temp;
					temp->next = next;
					current = NULL;
				*/}
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
					prev = current;
					current = next;
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
		(*list_of_moves)[0] = "sa";
	if ((*list_of_moves)[1])
		(*list_of_moves)[1] = "sb";
	if ((*list_of_moves)[2])
		(*list_of_moves)[2] = "ss";
	if ((*list_of_moves)[3])
		(*list_of_moves)[3] = "pa";
	if ((*list_of_moves)[4])
		(*list_of_moves)[4] = "pb";
	if ((*list_of_moves)[5])
		(*list_of_moves)[5] = "ra";
	if ((*list_of_moves)[6])
		(*list_of_moves)[6] = "rb";
	if ((*list_of_moves)[7])
		(*list_of_moves)[7] = "rr";
	if ((*list_of_moves)[8])
		(*list_of_moves)[8] = "rra";
	if ((*list_of_moves)[9])
		(*list_of_moves)[9] = "rrb";
	if ((*list_of_moves)[10])
		(*list_of_moves)[10] = "rrr";
}

char		**create_list_of_all_moves(void)
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
	t_node	*node;
	char	**the_move_list;
	int		index;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->rule = rule;
	node->parent = parent;
	node->weight = 0;
	node->a = ft_init_stack(pack->array, pack->size);
	node->b = ft_init_stack(NULL, 0);
	if (parent)
		node->steps = (parent->steps + 1);
	else
		node->steps = 0;
	the_move_list = moves_to_current(node);
	if (the_move_list)
	{
		index = 0;
		while (the_move_list[index])// && index < node->steps)
		{
			apply_rule(&(node->a), &(node->b), the_move_list[index]);
			index++;
		}
	}
	node->weight = calc_weight(node, final, pack);
	return (node);
}
/*
long	calc_h_value_riseing(t_list *list_a, t_list *list_b, t_pack *final)
{
	int		*the_solution_array;
	int		index;
	t_list	*current;
	long	h_value;

	the_solution_array = final->array;
	index = -1;
	h_value = 0;
	while(++index < final->size)
	{
		if (list_b)
		{
			if (list_b->value == the_solution_array[index])
				h_value = h_value + 1;
			else
				h_value = h_value + 3;
			list_b = list_b->prev;
		}
		else if (list_a)
		{
			if (list_a->value != the_solution_array[index])
				h_value = h_value + 2;
			list_a = list_a->next;
		}
	}
	return (h_value);
}*/

double	steps_to_solved_pos(int index, t_pack *final, int value, int avg)
{
	int		*solution_array;
	double	steps;
	
	solution_array = final->array;
	steps = 0;
	while (solution_array[index] != value)
	{
		steps++;
		index++;
		if (index >= final->size)
			index = 0;
	}
	steps = (steps > avg) ? (steps - avg) : steps;
	return (steps);
}

/*double	calc_h_value_stack_a(t_pack *final, t_list *list_a)
{
	int		*solution_array;
	int		index;
	t_list	*current;
	int		avg;
	double	h_value;

	if (final == NULL || list_a == NULL)
		return (0);
	solution_array = final->array;
	if (solution_array == NULL)
		return (0);
	index = final->size - 1;
	current = list_a;
	avg = (final->size / 2);
	h_value = 0;
	while (index >= 0 && current != NULL)
	{
		if (current->value != solution_array[index])
			h_value += steps_to_solved_pos(index, final, current->value, avg);
		current = current->prev;
		index--;
	}
	return (h_value);
}

double	calc_h_value_stack_b(t_pack *final, t_list *list_b)
{
	int		*solution_array;
	int		index;
	t_list	*current;
	int		avg;
	double	h_value;

	if (final == NULL || list_b == NULL)
		return (0);
	solution_array = final->array;
	if (solution_array == NULL)
		return (0);
	index = final->size - 1;
	current = list_b;
	avg = (final->size / 2);
	h_value = 0;
	while (index >= 0 && current != NULL)
	{
		if (current-> value != solution_array[index])
			h_value += steps_to_solved_pos(index, final, current->value, avg);
		current = current->next;
		index--;
	}
	return (h_value + 0.01);
}*/

int		index_of_current_val(int value, t_pack *final, int index)
{
	int		pos;
	int		*array;

	array = final->array;
	pos = -1;
	while (++pos < final->size)
	{
		if (value == array[pos])
			return (pos);
	}
	return (-1);
}

double	calc_block_stack_a(t_pack *final, t_stack *stack_a, int avg)
{
	t_list	*current;
	int		index;
	int		blocks;
	int		pos;
	double	dis;

	index = final->size;
	pos = 0;
	current = stack_a->back;
	dis = 0;
	blocks = 0;
	while (--index >= 0 && current != NULL)
	{
		if (current->value != (final->array)[index])
		{
			pos = index_of_current_val(current->value, final, index);
			if (pos > 0 && current->prev != NULL)
				if (current->prev->value == (final->array)[pos - 1])
				{
					current = current->prev;
					continue ;
				}
			blocks++;
			dis += steps_to_solved_pos(index, final, current->value, avg);
		}
		current = current->prev;
	}
	return ((dis == 0) ? 0 : (dis / blocks));
}

double	calc_block_stack_b(t_pack *final, t_stack *stack_b, int avg)
{
	t_list	*current;
	int		index;
	int		blocks;
	int		pos;
	double	dis;

	index = -1;
	current = stack_b->back;
	dis = 0;
	blocks = 1;
	while (++index < final->size && current != NULL)
	{
		if (current->value != (final->array)[index])
		{
			pos = index_of_current_val(current->value, final, index);
			if (pos > 0 && current->prev != NULL)
				if (current->prev->value == (final->array)[pos + 1])
				{
					current = current->prev;
					continue ;
				}
			blocks++;
			dis += 1 + steps_to_solved_pos(index, final, current->value, avg);
		}
		current = current->prev;
	}
	return ((dis == 0) ? (0 + blocks) : ((dis / blocks) + blocks));
}

double	calc_h_value(t_stack *stack_a, t_stack *stack_b, t_pack *final)
{
	double	h_value;
	int		avg;

	avg = (final->size / 2);
	h_value = 0;
	if(stack_a != NULL)
		if (stack_a->back != NULL)
			h_value += calc_block_stack_a(final, stack_a, avg);
	//	h_value += calc_h_value_stack_a(final, list_a);
	if (stack_b != NULL)
		if (stack_b->back)
			h_value += calc_block_stack_b(final, stack_b, avg);
//		h_value += calc_h_value_stack_b(final, stack_b);
	return (h_value);
}
// ----------- change the weight calculation to favour stack b a bit more ------------------
double	calc_weight(t_node *node, t_pack *final, t_pack *pack)
{
	double	h_value;

	h_value = calc_h_value(node->a, node->b, final);

	return (h_value + (node->steps));
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
void		apply_rule(t_stack **a, t_stack **b, char *rule)
{
	if (ft_strcmp("sa", rule) == 0)
		ft_SA_SB(*a);
	else if (ft_strcmp("sb", rule) == 0)
		ft_SA_SB(*b);
	else if (ft_strcmp("ss", rule) == 0)
		ft_SS(*a, *b);
	else if (ft_strcmp("pa", rule) == 0)
		ft_PA_PB(*b, *a);
	else if (ft_strcmp("pb", rule) == 0)
		ft_PA_PB(*a, *b);
	else if (ft_strcmp("ra", rule) == 0)
		ft_RA_RB(*a);
	else if (ft_strcmp("rb", rule) == 0)
		ft_RA_RB(*b);
	else if (ft_strcmp("rr", rule) == 0)
		ft_RR(*a, *b);
	else if (ft_strcmp("rra", rule) == 0)
		ft_RRA_RRB(*a);
	else if (ft_strcmp("rrb", rule) == 0)
		ft_RRA_RRB(*b);
	else if (ft_strcmp("rrr", rule) == 0)
		ft_RRR(*a, *b);
}

/*
** ------------------------>in file ft_rules.c<---------------------------------
*/
void	ft_SA_SB(t_stack *a)
{
//	t_list *b;
	t_list	*to_be_2;
	t_list	*to_be_1;
	t_list	*is_3;

	if(a->front)
	{
		if(a->front->next)
		{
			to_be_1 = a->front->next;
			to_be_2 = a->front;
			is_3 = to_be_1->next;
			to_be_1->prev = NULL;
			to_be_1->next = to_be_2;
			to_be_2->prev = to_be_1;
			to_be_2->next = is_3;
			a->front = to_be_1;
			if (is_3 == NULL)
				a->back = to_be_2;
			else
				is_3->prev = to_be_2;

//			b = a->front->next; /* store b, so you can use it to access c, B IS ALSO SOON TO BE FIRST */
//			a->front->prev = b; /* since a will no longer be first, point it to what was second (this case b)*/
//			a->front->next = b->next; /* use b to access c which is the third elemnt */
//			b->prev = NULL; /*the first element cant have a prev right? */
//			b->next = a->front; /* again since b is to be first and a is to be second, then its next should be what was first */
//			a->front = b; /* WE FINALLY CROWN B AS NEW KING */
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
		if (from->back == from->front)
			from->back = NULL;
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
		if(a->back == a->front && a->front != NULL)
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