#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

/*
**	read_instructions()
**	reads one instruction at a time from stdin
**	can return them in a loop to calling function which can then send to function-
**	to apply the rule.
*/

void		read_instructions()
{
	char *rule;
	int i;

	i = 0;

	rule = NULL;
	while (get_next_line(0, &rule) && i < 10)
	{
		printf("- %s\n", rule);
		i++;
	}
}

/*
**	ch_main()
**	verifies input arg like ps_main
**	
*/

int		main(int argc, char **argv)
{
	t_pack	pack;

	read_instructions();
	if (!(verify_argc(argc)))
		return (1);
	if (!(verify_args(argv[1], &pack)))
		return (1);
	ft_putstr("OK/KO\n");//example output based on return of a function
	return (0);
}
