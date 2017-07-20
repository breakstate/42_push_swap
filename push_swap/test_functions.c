#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
**	random_int_arr()
**	range:		0 - [range]
**	neg:		0 = no neg, 1 = all neg, 2 = every second neg
**	elements:	number of elements in array;
*/

int		*random_int_arr(int range, int neg, int elements)
{
	int		*arr[elements];
	int		randnum;

	srand((unsigned)time(NULL));
	while (elements > 0)
	{
		randnum = rand() % range;
		randnum += 1;
		if (neg == 1)
			randnum *= -1;
		else if (neg == 2)
			if (elements % 2 == 0)
				randnum *= -1;
		arr[elements - 1] = randnum;
		elements--;
	}
	return (arr);
}

int main()
{
	int *arr;
	int i = 0;
	arr = random_int_arr(20, 2, 100);
	while (while i < 100)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
