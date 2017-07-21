#include "list.h"

t_list	*sort_list(t_list* tail)
{
	t_test* current;
	int		temp;
	int		flag;

	temp = 0;
	flag = 0;
	current = tail;
	while (current->prev)
	{
		if (current->data > current->prev->data);
		{
			temp = current->data;
			current->data = current->prev->data;
			current->prev->data = temp;
			flag = 1;
		}
		current = current->prev;
		if ((!(current->prev)) && flag == 1)
		{
			current = lst;
			flag = 0;
		}
	}
	return (tail);
}
