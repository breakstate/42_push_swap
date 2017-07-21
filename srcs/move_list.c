#include "push_swap.h"

/*
**function moves up the parent nodes storing moves made
** return a list of the moves
** have to free return
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