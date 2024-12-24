/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotationals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:44:58 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/24 20:57:21 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_rotate_both_rev_by_bool(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_bool)
{
	size_t	i;
	size_t	i_prepend_b;
	size_t	i_num;
	size_t	size_a;

	if (rev_bool)
	{
		i = 0;
		i_prepend_b = index_to_prepend(stack_b, num);
		size_a = size(stack_a);
		i_num = num_index(stack_a, num);
		if (i_prepend_b)
			i = size(stack_b) - i_prepend_b;
		if (i_num && (i < (size_a - i_num)))
			i = size_a - i_num;
	}
	else
	{
		i = index_for_prepend(stack_b);
		i_num = num_index(stack_a, num);
		if (i < i_num)
			i = i_num;
	}
	return (i);
}

size_t	count_rotate_both_rev_by_i(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_arg_index)
{
	size_t	i;
	size_t	i_num;
	size_t	i_prepend;

	i = 0;
	if (rev_arg_index)
	{
		i_prepend = index_for_prepend(stack_b, num);
		if (i_prepend)
			i = size(stack_b) - i_prepend;
		i = i + index_for_prepend(stack_a, num);
		return (i);
	}
	else
	{
		i_num = num_index(stack_a, num);
		if (i_num)
			i = size(stack_a) - i_num;
		i = i + index_for_prepend(stack_b, num);
		return (i);
	}
}

size_t	latest_cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, int num, size_t cheapest_before)
{
	int		i;
	size_t	count;

	i = cheapest_before;
	count = count_rotate_both_rev_by_bool(stack_a, stack_b, num, 0);
	if (count < i)
		i = count;
	count = count_rotate_both_rev_by_bool(stack_a, stack_b, num, 1);
	if (count < i)
		i = count;
	count = count_rotate_both_rev_by_i(stack_a, stack_b, num, 0);
	if (count < i)
		i = count;
	count = count_rotate_both_rev_by_i(stack_a, stack_b, num, 1);
	if (count < i)
		i = count;
	return (i);
}

size_t	find_cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, int push_arg_index)
{
	t_elem	*initial;
	t_elem	*current;
	size_t	i;

	if (push_arg_index)
		initial = *stack_b;
	else
		initial = *stack_a;
	i = count_rotate_both_rev_by_bool(stack_a, stack_b, initial->num, 1);
	i = latest_cheapest_rotation(stack_a, stack_b, initial->num, i); // RECONSIDER
	current = initial->next;
	while (current != initial)
	{
		i = latest_cheapest_rotation(stack_a, stack_b, initial->num, i);
		current = current->next;
	}
	return (i);
}
