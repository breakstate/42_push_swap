#include "push_swap.h"

void		apply_rule(char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp("SA", move) == 0)
		ft_SA_SB(a);
	if (ft_strcmp("SB", move) == 0)
		ft_SA_SB(b);
	if (ft_strcmp("SS", move) == 0)
		ft_SS(a, b);
	if (ft_strcmp("PA", move) == 0)
		ft_PA_PB(b, a);
	if (ft_strcmp("PB", move) == 0)
		ft_PA_PB(a, b);
	if (ft_strcmp("RA", move) == 0)
		ft_RA_RB(a);
	if (ft_strcmp("RB", move) == 0)
		ft_RA_RB(b);
	if (ft_strcmp("RR", move) == 0)
		ft_RR(a, b);
	if (ft_strcmp("RRA", move) == 0)
		ft_RRA_RRB(a);
	if (ft_strcmp("RRB", move) == 0)
		ft_RRA_RRB(b);
	if (ft_strcmp("RRR", move) == 0)
		ft_RRR(a, b);
}