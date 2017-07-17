#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

void	read_instructions()
{
	//with the use of GNL
}

int		main(int argc, char **argv)
{
	t_pack	pack;
	
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
	ft_putstr("winner winner chicken dinner");
	return (0);
}
