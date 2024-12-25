/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotational_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:09:43 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/25 21:11:32 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_until_pushworthy(
		t_elem **src, t_elem **dest, int num, int rev_and_push_bools)
{
	void(*rotate_single)(t_elem **stack, char name);
	void(*rotate_double)(t_elem **stack1, t_elem **stack2);

	if (rev_and_push_bools >> 1)
	{
		rotate_single = rotate;
		rotate_double = rotate_both;
	}
	else
	{
		rotate_single = rev_rotate;
		rotate_double = rev_rotate_both;
	}
	// FIGURE OUT AN ALTERNATIVE OR EXPLANATION TO 'a' + bitwise
	while ((*src)->num != num
			&& index_for_prepend(dest, num, rev_and_push_bools & 1))
		rotate_double(src, dest);
	while (index_for_prepend(dest, num, rev_and_push_bools & 1))
		rotate_single(dest, 'a' + (rev_and_push_bools & 1));
	while ((*src)->num != num)
		rotate_single(src, 'a' + (rev_and_push_bools & 1));
}

static bool	rotate_rev_by_bool(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_and_push_bools)
{
	if (rev_and_push_bools & 1)
		rotate_both_until_pushworthy(stack_a, stack_b, num, rev_and_push_bools);
	else
		rotate_both_until_pushworthy(stack_b, stack_a, num, rev_and_push_bools);
	return (1);
}

static void	rotate_counter_until_pushworthy(
		t_elem **src, t_elem **dest, int num, int counter_and_push_bools)
{
	void(*rotate_src)(t_elem **stack, char name);
	void(*rotate_dest)(t_elem **stack1, char name);

	if (counter_and_push_bools >> 1)
	{
		rotate_src = rev_rotate;
		rotate_dest = rotate;
	}
	else
	{
		rotate_src = rotate;
		rotate_dest = rev_rotate;
	}
	// FIGURE OUT AN ALTERNATIVE OR EXPLANATION TO 'a' + bitwise
	while (index_for_prepend(dest, num, counter_and_push_bools & 1))
		rotate_dest(dest, 'a' + (counter_and_push_bools & 1));
	while ((*src)->num != num)
		rotate_src(src, 'a' + (counter_and_push_bools & 1));
}

static bool	rotate_counter_by_index(
		t_elem **stack_a, t_elem **stack_b, int num, int counter_and_push_bools)
{
	if (counter_and_push_bools & 1)
		rotate_counter_until_pushworthy(
				stack_a, stack_b, num, counter_and_push_bools);
	else
		rotate_counter_until_pushworthy(
				stack_b, stack_a, num, counter_and_push_bools ^ 2);
	return (1);
}

// stack params shortened to 'a' & 'b' to stay under norm's 80 chars per line
void	do_cheapest_rotation(t_elem **a, t_elem **b, bool push_arg_i)
{
	size_t	cheapest;
	bool	rotated;
	t_elem	*elem;

//	print_stack(a, 'a');
//	print_stack(b, 'b');
//	ft_printf("looking for cheapest, push_arg_i = %i\n", push_arg_i);
	cheapest = find_cheapest_rotation(a, b, push_arg_i);
//	ft_printf("found cheapest\n");
	rotated = 0;
	if (push_arg_i)
		elem = *a;
	else
		elem = *b;
	while (!rotated)
	{
//		ft_printf("%i\n", rotated + 48);
		if (cheapest == i_of_rotates_rev_by_bool(a, b, elem->num, 0))
			rotated = rotate_rev_by_bool(a, b, elem->num, push_arg_i);
		else if (cheapest == i_of_rotates_rev_by_bool(a, b, elem->num, 1))
			rotated = rotate_rev_by_bool(a, b, elem->num, 2 | push_arg_i);
		else if (cheapest == i_of_rotates_rev_by_index(a, b, elem->num, 0))
			rotated = rotate_counter_by_index(a, b, elem->num, push_arg_i);
		else if (cheapest == i_of_rotates_rev_by_index(a, b, elem->num, 1))
			rotated = rotate_counter_by_index(a, b, elem->num, 2 | push_arg_i);
		else
			elem = elem->next;
	}
}
