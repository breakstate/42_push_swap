sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.



static void	stack_b_rules(char *rule, t_stacks *stacks)
{
	int		temp;
	int		temp2;

	temp = 0;
	if (ft_strcmp(rule, "sb") == 0)
	{
		if (stacks->stack_b[1] == INT_MIN)
			return ;
		temp = stacks->stack_b[1];
		stacks->stack_b[1] = stacks->stack_b[0];
		stacks->stack_b[0] = temp;
	}
	if (ft_strcmp(rule, "pb") == 0)
	{
		temp = 0;
		temp2 = 0;
		if (stacks->stack_a[stacks->size_of_stacks - 1] == INT_MIN)
			return ;
		while (stacks->stack_a[temp] == INT_MIN)
			temp++;
		while (stacks->stack_b[temp2] == INT_MIN)
			temp2++;
		stacks->stack_b[temp2 + 1] = stacks->stack_a[temp];
		stacks->stack_a[temp] = INT_MIN;
}

static void	stack_ab_rules(char *rule, t_stacks *stacks)
{
	int		temp;

	temp = 0;
}
void		apply_rule(char *rule, t_stacks *stacks)
{
	if (ft_strcmp(rule, "sa") == 0)
		sa(stacks);
	if (ft_strcmp(rule, "pa") == 0)
		pa(stacks);
	if (ft_strcmp(rule, "ra") == 0)
		ra(stacks);
	if (ft_strcmp(rule, "rra") == 0)
		rra(stacks);
	if (ft_strcmp(rule, "sb") == 0)
		sb(stacks);
	if (ft_strcmp(rule, "pb") == 0)
		pb(stacks);
	if (ft_strcmp(rule, "rb") == 0)
		rb(stacks);
	if (ft_strcmp(rule, "rrb") == 0)
		rrb(stacks);
	if (ft_strcmp(rule, "ss") == 0)
		ss(stacks);
	if (ft_strcmp(rule, "rr") == 0)
		rr(stacks);
	if (ft_strcmp(rule, "rrr") == 0)
		rrr(stacks);
}