#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	if (stacks->stack_a[1] == INT_MIN)
		return ;
	while (stacks->stack_a[temp2] != INT_MIN)
		temp2++;
	temp = stacks->stack_a[temp2 - 1];
	stacks->stack_a[temp2 - 1] = stacks->stack_a[temp2];
	stacks->stack_a[temp2] = temp;
}

void	pa(t_stacks *stacks)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	if (stacks->stack_b[stacks->size_of_stacks - 1] == INT_MIN)
		return ;
	while (stacks->stack_b[temp] == INT_MIN)
		temp++;
	while (stacks->stack_a[temp2] == INT_MIN)
		temp2++;
	stacks->stack_a[temp2 + 1] = stacks->stack_b[temp];
	stacks->stack_b[temp] = INT_MIN;
}

void	ra(t_stacks *stacks)
{}

void	rra(t_stacks *stacks)
{}