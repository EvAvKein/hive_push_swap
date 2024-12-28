/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:58:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/28 19:22:36 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

bool	is_sorted(t_elem **stack)
{
	t_elem	*initial;
	t_elem	*current;

	initial = *stack;
	current = initial;
	while (current->next != initial)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

size_t	size(t_elem **stack)
{
	t_elem	*initial;
	t_elem	*current;
	size_t	size;

	if (!stack || !*stack)
		return (0);
	initial = *stack;
	current = initial;
	size = 1;
	while (current->next != initial)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	smallest_and_largest(t_elem **stack, int *smallest, int *largest)
{
	t_elem	*initial;
	t_elem	*current;

	initial = *stack;
	current = initial;
	if (smallest)
		*smallest = initial->num;
	if (largest)
		*largest = initial->num;
	while (current->next != initial)
	{
		current = current->next;
		if (smallest && current->num < *smallest)
			*smallest = current->num;
		if (largest && current->num > *largest)
			*largest = current->num;
	}
}

size_t	index_for_prepend(t_elem **stack, int new, bool descending)
{
	int		smallest;
	int		largest;
	t_elem	*initial;
	t_elem	*current;
	size_t	i;

	initial = *stack;
	smallest_and_largest(stack, &smallest, &largest);
	if (new > largest)
		return ((num_index(stack, largest) + !descending) % size(stack));
	if (new < smallest)
		return ((num_index(stack, smallest) + descending) % size(stack));
	current = initial;
	i = 0;
	while (!i || (current != initial))
	{
		if (descending && ((new < current->num)
			|| (new > current->next->num)))
			return ((i + 1) % size(stack));
		if (!descending && ((new > current->num)
			|| (new < current->prev->num)))
			return ((i - 1) % size(stack));	
		current = current->next;
		i++;
	}
	return (i);
}
