/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotational_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:44:58 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/30 19:59:08 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	rotations_both_until_pushworthy(
		t_elem **src, t_elem **dest, int num, int rev_and_push_bools)
{
	size_t	i;
	size_t	i_prepend;
	size_t	i_num;
	size_t	size_src;

	if (rev_and_push_bools >> 1)
	{
		i = 0;
		i_prepend = index_for_prepend(dest, num, rev_and_push_bools & 1);
		i_num = num_i(src, num);
		size_src = size(src);
		if (i_prepend)
			i = size(dest) - i_prepend;
		if (i_num && (i < (size_src - i_num)))
			i = size_src - i_num;
	}
	else
	{
		i = index_for_prepend(dest, num, rev_and_push_bools & 1);
		i_num = num_i(src, num);
		if (i < i_num)
			i = i_num;
	}
	return (i);
}

size_t	rotations_rev_by_bool(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_and_push_bools)
{
	if (rev_and_push_bools & 1)
		return (rotations_both_until_pushworthy(
					stack_a, stack_b, num, rev_and_push_bools));
	else
		return (rotations_both_until_pushworthy(
					stack_b, stack_a, num, rev_and_push_bools));
}

static size_t	rotations_counter_until_pushworthy(
		t_elem **src, t_elem **dest, int num, int rev_and_push_bools)
{
	size_t	i;
	size_t	i_num;
	size_t	i_prepend;

	i = 0;
	if (rev_and_push_bools >> 1)
	{
		i_prepend = index_for_prepend(dest, num, rev_and_push_bools & 1);
		if (i_prepend)
			i = size(dest) - i_prepend;
		i = i + index_for_prepend(src, num, rev_and_push_bools & 1);
	}
	else
	{
		i_num = num_i(src, num);
		if (i_num)
			i = size(src) - i_num;
		i = i + index_for_prepend(dest, num, rev_and_push_bools & 1);
	}
	return (i);
}

size_t	rotations_counter_by_index(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_and_push_bools)
{
	if (rev_and_push_bools & 1)
		return (rotations_counter_until_pushworthy(
					stack_a, stack_b, num, rev_and_push_bools));
	else
		return (rotations_counter_until_pushworthy(
					stack_b, stack_a, num, rev_and_push_bools));
}

size_t	find_cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, bool push_arg_i)
{
	t_elem	*initial;
	t_elem	*current;
	ssize_t	cheapest;
	bool	first_check;

	if (push_arg_i)
		initial = *stack_a;
	else
		initial = *stack_b;
	cheapest = rotations_rev_by_bool(stack_a, stack_b, initial->num, push_arg_i);
	current = initial;
	first_check = 1;
	while (first_check || (current != initial))
	{
		set_if_lower(&cheapest,
				rotations_rev_by_bool(stack_a, stack_b, current->num, push_arg_i));
		set_if_lower(&cheapest,
				rotations_rev_by_bool(stack_a, stack_b, current->num, 2 | push_arg_i));
		set_if_lower(&cheapest,
				rotations_counter_by_index(stack_a, stack_b, current->num, push_arg_i));
		set_if_lower(&cheapest,
				rotations_counter_by_index(stack_a, stack_b, current->num, 2 | push_arg_i));
		current = current->next;
		first_check = 0;
	}
	return (cheapest);
}
