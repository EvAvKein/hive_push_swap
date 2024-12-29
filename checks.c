/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:58:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/29 20:19:08 by ekeinan          ###   ########.fr       */
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

void	smallest_largest_and_size(t_elem **stack, int *smallest, int *largest, size_t *size)
{
	t_elem	*initial;
	t_elem	*current;
	size_t	counter;

	initial = *stack;
	current = initial;
	*smallest = initial->num;
	*largest = initial->num;
	counter = 1;
	while (current->next != initial)
	{
		current = current->next;
		if (current->num < *smallest)
			*smallest = current->num;
		if (current->num > *largest)
			*largest = current->num;
		counter++;
	}
	*size = counter;
}

size_t	index_for_prepend(t_elem **stack, int new, bool descending)
{
	long long	sm_and_lg;
	size_t		size;
	t_elem		*initial;
	t_elem		*current;
	size_t		i;

	initial = *stack;
	smallest_largest_and_size(stack, (int*)&sm_and_lg, (int*)(&sm_and_lg) + 1, &size);
	if (new > (sm_and_lg >> sizeof(int) * 8))
		return (num_index(stack, (sm_and_lg >> ((sizeof(int) * 8))) + !descending) % size);
	if (new < (sm_and_lg & INT_MAX))
		return (num_index(stack, (int)(sm_and_lg & INT_MAX) + descending) % size);
	current = initial;
	i = 0;
	while (!i || (current != initial))
	{
		if (descending && ((new < current->num)
			&& (new > current->next->num)))
			return ((i + 1) % size);
		if (!descending && ((new > current->num)
			&& (new < current->next->num)))
			return ((i + 1) % size);
		current = current->next;
		i++;
	}
	return (0);
}
