#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

void	read_instructions()
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
	}
}

int		main(int argc, char **argv)
{
	t_pack	pack;

	read_instructions();	
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
	ft_putstr("winner winner chicken dinner\n");
	return (0);
}
