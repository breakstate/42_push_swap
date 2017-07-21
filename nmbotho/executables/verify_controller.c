#include "../includes/ft_push_swap.h"
#include "../../libft/includes/libft.h"

int			verify_args(char *arg, t_pack *pack)
{
	char	**split_args;

	if (!(verify_digits(arg) && arg[0] != '\0'))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	split_args = ft_strsplit(arg, ' ');
	if (!(verify_int(split_args) && split_args[0] != '\0'))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (arr_stoi(split_args, pack));
}

int			verify_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
