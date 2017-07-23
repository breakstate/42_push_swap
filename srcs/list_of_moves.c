#include "push_swap.h"

static void	assaign_rule_list(char	***list_of_moves)
{
	if ((*list_of_moves)[0])
		(*list_of_moves)[0] = "SA";
	if ((*list_of_moves)[1])
		(*list_of_moves)[1] = "SB";
	if ((*list_of_moves)[2])
		(*list_of_moves)[2] = "SS";
	if ((*list_of_moves)[3])
		(*list_of_moves)[3] = "PA";
	if ((*list_of_moves)[4])
		(*list_of_moves)[4] = "PB";
	if ((*list_of_moves)[5])
		(*list_of_moves)[5] = "RA";
	if ((*list_of_moves)[6])
		(*list_of_moves)[6] = "RB";
	if ((*list_of_moves)[7])
		(*list_of_moves)[7] = "RR";
	if ((*list_of_moves)[8])
		(*list_of_moves)[8] = "RRA";
	if ((*list_of_moves)[9])
		(*list_of_moves)[9] = "RRB";
	if ((*list_of_moves)[10])
		(*list_of_moves)[10] = "RRR";
}

char		**list_of_moves(void)
{
	char	**list_of_moves;
	int		index;

	list_of_moves = (char **)malloc(sizeof(char *) * 11);
	if (list_of_moves)
	{
		index = -1;
		while (++index <= 10)
			list_of_moves[index] = ft_memalloc(sizeof(char) * 4);
		assaign_rule_list(&list_of_moves);
	}
	return (list_of_moves);
}
