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
	//a_star(&pack);
	while (i < pack.size)
		printf("---> %d\n", pack.array[i++]);
	return (0);
}
