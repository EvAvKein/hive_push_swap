/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotational_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:44:58 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/25 21:11:45 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	i_of_rotates_rev_by_bool(
		t_elem **stack_a, t_elem **stack_b, int num, bool rev_bool)
{
	size_t	i;
	size_t	i_prepend_b;
	size_t	i_num;
	size_t	size_a;

	if (rev_bool)
	{
		i = 0;
		i_prepend_b = index_for_prepend(stack_b, num, 1);
		size_a = size(stack_a);
		i_num = num_index(stack_a, num);
		if (i_prepend_b)
			i = size(stack_b) - i_prepend_b;
		if (i_num && (i < (size_a - i_num)))
			i = size_a - i_num;
	}
	else
	{
		i = index_for_prepend(stack_b, num, 1);
		i_num = num_index(stack_a, num);
		if (i < i_num)
			i = i_num;
	}
	return (i);
}

size_t	i_of_rotates_rev_by_index(
		t_elem **stack_a, t_elem **stack_b, int num, bool rev_arg_i)
{
	size_t	i;
	size_t	i_num;
	size_t	i_prepend;

	i = 0;
	if (rev_arg_i)
	{
//		ft_printf("case 0\n");
		i_prepend = index_for_prepend(stack_b, num, 1);
//		ft_printf("case 1\n");
		if (i_prepend)
			i = size(stack_b) - i_prepend;
//		ft_printf("case 2\n");
		i = i + index_for_prepend(stack_a, num, 1);
//		ft_printf("case 3\n");
		return (i);
	}
	else
	{
		i_num = num_index(stack_a, num);
		if (i_num)
			i = size(stack_a) - i_num;
		i = i + index_for_prepend(stack_b, num, 1);
		return (i);
	}
}

static size_t	cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, int num, size_t cheapest_before)
{
	size_t	cheapest;
	size_t	count;

	cheapest = cheapest_before;
//	ft_printf("cheapest 0 = %i (num = %i)\n", cheapest, num);
	count = i_of_rotates_rev_by_bool(stack_a, stack_b, num, 0);
	if (count < cheapest)
		cheapest = count;
//	ft_printf("cheapest 1 = %i\n", cheapest);
	count = i_of_rotates_rev_by_bool(stack_a, stack_b, num, 1);
	if (count < cheapest)
		cheapest = count;
//	ft_printf("cheapest 2 = %i\n", cheapest);
	count = i_of_rotates_rev_by_index(stack_a, stack_b, num, 0);
	if (count < cheapest)
		cheapest = count;
//	ft_printf("cheapest 3 = %i\n", cheapest);
	count = i_of_rotates_rev_by_index(stack_a, stack_b, num, 1);
	if (count < cheapest)
		cheapest = count;
//	ft_printf("cheapest 4 = %i\n", cheapest);
	return (cheapest);
}

size_t	find_cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, bool push_arg_i)
{
	t_elem	*initial;
	t_elem	*current;
	size_t	cheapest;

	if (push_arg_i)
		initial = *stack_b;
	else
		initial = *stack_a;
	cheapest = i_of_rotates_rev_by_bool(stack_a, stack_b, initial->num, 1);
//	ft_printf("past first\n");
	cheapest = cheapest_rotation(stack_a, stack_b, initial->num, cheapest);
//	ft_printf("past second\n");
	current = initial->next;
	while (current != initial)
	{
		cheapest = cheapest_rotation(stack_a, stack_b, initial->num, cheapest);
		current = current->next;
	}
	return (cheapest);
}
