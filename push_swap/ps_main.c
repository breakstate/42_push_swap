#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int		*verify_args(char *arg)
{
	char	**split_args;
	int		*int_arr;

	if (!(verify_digits(arg)))
		return (NULL);
	split_args = ft_strsplit(arg, ' ');
	if (!(verify_int(split_args)))
		return (NULL);
	//if ((int_arr = arr_stoi(split_arg)) != NULL)
	//	return(
	return (arr_stoi(split_args));
}

int main(int argc, char ** argv)
{
	int *int_arr;
	int i;

	i = 0;
	if (argc == 1)
	{
		ft_putendl("Please specify ARG");
		return (1);
	}
	if (!(int_arr = verify_args(argv[1])))
		ft_putstr("Error\n");
	ft_putstr("test\n");
	while (int_arr[i])
	{
		printf("%d\n", int_arr[i]);
		i++;
	}
	return (0);
}
