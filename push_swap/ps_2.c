int			verify_digits(int argc, char **argv)
{
	int		i;

	i = 1;
	while(argv[i])
	{
		if (!(ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j])))
		{
			return (0)
		}
		i++;
	}
	return (1);
}

int			verify_dup(char **argv)
{
	int		i;
	int		j;
	int		pos;
	char	*arr;

	arr = ft_strsplit(argv, ' ');
	i = 0;
	j = 0;
	while (arr[i])
	{
		pos = i;
		while (arr[i + 1])
		{
			if (ft_strcmp(arr[i], argv[i + 1]) != 0)
				i++;
			else
				return (0);
		}
		i = pos + 1;
	}
	return (1);//or what next verifaction returns
}

/* 
**	notes
** 	int		verify_int()//combine conver() and verify_if_int()
**	ascii to long
**	check if long <= max int(stored in long) && >= min int(stored in long)
*/
