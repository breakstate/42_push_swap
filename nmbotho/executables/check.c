

int		list_cmp(t_TYPE *head_a, t_TYPE *head_b)
{
	t_TYPE	*current_a;
	t_TYPE	*current_b;

	current_a = head_a;
	current_b = head_b;
	while (current_a)
	{
		if (current_a->data != current_b->data)
		{
			ft_putstr("KO\n");
			return (0);
		}
		current_a = current_a->next;
		current_b = current_b->next;
	}
	return (1);
}
