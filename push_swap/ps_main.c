#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_pack	pack;
	int		i;

	i = 0;
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
//	ft_nhlaka(pack.int_arr, pack.elements);//handoff to Nhlaka
	while (i < pack.elements)
	printf("---> %d\n", pack.int_arr[i++]);
	return (0);
}