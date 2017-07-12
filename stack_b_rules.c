#include "push_swap.h"

void	sb(t_stacks *stacks)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	if (stacks->stack_b[1] == INT_MIN)
		return ;
	while (stacks->stack_b[temp2] == INT_MIN)
		temp2++;
	temp = stacks->stack_b[temp2 - 1];
	stacks->stack_b[temp2 - 1] = stacks->stack_b[temp2];
	stacks->stack_b[temp2] = temp;
}
void	pb(t_stacks *stacks)
{
	int		temp;
	int		temp2;

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

void	rb(t_stacks *stacks)
{}

void	rrb(t_stacks *stacks)
{}