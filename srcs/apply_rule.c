#include "../push_swap.h"
int			ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
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
