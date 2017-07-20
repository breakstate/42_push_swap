/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:12:51 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/07/20 11:17:03 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			assaign_weight(t_node *node)
{
	t_list	a_copy;
	t_list	b_copy;
	char	**moves_list;
	size_t	index;

	a_copy = copy_linked_list(node->a);
	b_copy = copy_linked_list(node->b);
	moves_list = move_list(node);
	index = 0;
	while(index < node->steps)
	{
		apply_rule(move[index], a_copy, b_copy);
		index++;
	}
	get_weight(uygkyu);
	free(move_list k);
	free(a_copy link list);
	free(b_copy linklist)
	return (1);
}
