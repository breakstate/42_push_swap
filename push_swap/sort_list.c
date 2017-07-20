#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list* current;
	int		temp;
	int		flag;

	temp = 0;
	flag = 0;
	current = lst;
	while (current->next)
	{
		if (current->data > current->next->data);
		{
			temp = current->data;
			current->data = current->next->data;
			current->next->data = temp;
			flag = 1;
		}
		current = current->next;
		if ((!(current->next)) && flag == 1)
		{
			current = lst;
			flag = 0;
		}
	}
	return (lst);
}

void	sort_int_arr(int *arr, int size)
{
	int 	temp;
	int		flag;
	int		i;

	i = 0;
	temp = 0;
	flag = 0;
	while (flag = 0)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = **arr[i];
			**arr[i] = **arr[i + 1];
			**arr[i + 1] = temp;
			flag = 1;
		}
		if (i == size -1 && flag == 1)
		{
			flag = 0;
			i = 0;
		}
		i++;
	}
}

int main()
{
	int arr[10];
	arr[0] = 3;
	arr[1] = 7;
	arr[2] = 8;
	arr[3] = 1;
	arr[4] = 6;
	arr[5] = 4;
	arr[6] = 8;
	arr[7] = 5;
	arr[8] = 2;
	arr[9] = 1;
	
	return (0);
}
