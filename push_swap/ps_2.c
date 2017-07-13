#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

/*
**	verify_digits()
**	returns 1 if verified only digits
**	returns 0 if non-digits detected
*/
int			verify_digits(char *argv)
{
	int		i;

	i = 0;
	while(argv[i])
	{
		if (!(ft_isdigit(argv[i]) || ft_isspace(argv[i])))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
**	verify_dup()
**	returns 1 if verfied no duplicates
**	returns 0 if duplicates detected
*/
int			verify_dup(char *arg)
{
	int		i;
	int		j;
	int		pos;
	char	**arr;

	arr = ft_strsplit(arg, ' ');
	i = 0;
	j = 1;
	while (arr[i])
	{
		pos = i;
		while (arr[i + j])
		{
			if (ft_strcmp(arr[i], arr[i + j]) != 0)
				j++;
			else
				return (0);
		}
		j = 1;
		i = pos + 1;
	}
	return (1);//or what next verifaction returns
}

/*
**	verify_int()
**	returns 1 if verified all elements fit into int
**	returns 0 if element > int detected
*/
int			verify_min_max(long num)
{
	int		int_high;
	int		int_low;

	int_high = 2147483647;
	int_low = -2147483648;
	if (num < int_low || num > int_high)
		return (0);
	return (1);
}

int			verify_int(char **arg)
{
	int		sign;
	int		i;
	int		j;
	long	result;

	sign = 1;
	i = 0;
	j = 0;
	result = 0;
	while (arg[i])
	{
		result = 0;
		if (arg[i][j] == '-')
			sign = -1;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j] != '\0')
		{
			result = ((result * 10) + (arg[i][j] - 48));
			j++;
		}
		result = result * sign;
		if (!(verify_min_max(result)))
			return (0);
		i++;
		j = 0;
	}
	return (1);
}
/* 
**	notes
** 	0 is bad, 1 is good, can be reversed if preferred
**	push_swap.h modified to compile, changes not pushed
**	
*/

int main()
{
	char *str;
	str = "21 23 45 67 89 90 167 7 -2147483649 ";
	printf("verify_dup output - %d\n", verify_int(ft_strsplit(str, ' ')));
	return (0);
}
