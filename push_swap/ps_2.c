int		verify_int(int argc, char **argv)
{
	int i;
	int j;
	char **

	i = 1;
	j = 0;

	while(i < argc)
	{
		while (j != '\0')
		{
			if (!(ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j])))
			{
				return (0)
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);//return from next verification
}

int		verify_dup(int argc, char **argv)
{
	int i;
	int pos;
	cha

	i = 1;
	while (i < argc)
	{
		pos = i;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) != 0)
				i++;
			else
				return (0);
		}
		i = pos + 1;
	}
	return (1);//or what next verifaction returns
}

int		verify_int()
ascii to long
check if long <= max int(stored in long) && >= min int(stored in long)

