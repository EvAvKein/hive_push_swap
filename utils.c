/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:02:03 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/25 21:13:47 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*stack_clear(t_elem **elem)
{
	t_elem	*first;
	t_elem	*current;
	t_elem	*following;

	if (!elem || !*elem)
		return (NULL);
	first = *elem;
	current = *elem;
	while (current)
	{
		following = current->next;
		free(current);
		if (following == first)
			break ;
		current = following;
	}
	*elem = NULL;
	return (NULL);
}

size_t	num_index(t_elem **stack, int num)
{
	t_elem	*initial;
	t_elem	*current;
	size_t	i;

	initial = *stack;
	if (initial->num == num)
		return (0);
	current = initial->next;
	i = 1;
	while (current != initial)
	{
		if (current->num == num)
			return (i);
		current = current->next;
		i++;
	}
/*	if (current->num != num)
	{
		ft_printf("BUG: Looking for num index in a stack without it\n");
		return (0);
	}
*/
	return (i);
}
