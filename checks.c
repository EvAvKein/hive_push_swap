/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:58:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/24 20:59:39 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	is_sorted(t_elem **stack)
{
	t_elem	*initial;
	t_elem	*current;
	int		num;

	initial = *stack;
	current = initial;
	num = initial->num;
	while (current->next != initial)
	{
		current = current->next;
		if (current->num < num)
			return (0);
		num = current->num;
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
	t_elem		*initial;
	t_elem		*current;

	if (!stack || !*stack)
	{
		ft_printf("BUG: Looking for smallest and largest in empty stack\n");
		return (0);
	}
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

size_t	index_for_prepend(t_elem **stack, int new, int descending)
{
	int		smallest;
	int		largest;
	t_elem	*initial;
	t_elem	*current;
	size_t	i;

	initial = *stack;
	if ((new > initial->num) == descending
		&& (new < initial->prev->num) == descending)
		return (0);
	smallest_and_largest(stack, &smallest, &largest);
	if ((new > largest) == descending
		|| (new < smallest) == descending)
		return (num_index(stack, largest));
	current = initial->next;
	i = 1;
	while (current != initial)
	{
		if ((new < current->num) == descending
			&& (new > current->next->num) == descending)
			return (i);
		i++;
	}
	ft_printf("BUG: Didn't find index for prepend\n");
	return (i);
}
