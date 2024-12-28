/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:36:26 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/28 16:27:59 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_up_to_three(t_elem **stack, char name)
{
	int		smallest;
	int		largest;

	if (size(stack) == 2)
		return (rotate(stack, name));
	smallest_and_largest(stack, &smallest, &largest);
	if ((*stack)->num == largest)
	{
		rotate(stack, name);
		if (!is_sorted(stack))
			swap(stack, name);
	}
	else if ((*stack)->num == smallest)
	{
		rev_rotate(stack, name);
		swap(stack, name);
	}
	else
	{
		if ((*stack)->next->num == largest)
			rev_rotate(stack, name);
		else
			swap(stack, name);
	}
}

static void	turks_init(t_elem **stack_a, t_elem **stack_b, size_t length)
{
	push(stack_a, stack_b, 'b');
	if (length > 4)
	{
		push(stack_a, stack_b, 'b');
		if (is_sorted(stack_b))
			rotate(stack_b, 'b');
	}
	if (length <= 5 && !is_sorted(stack_a))
		sort_up_to_three(stack_a, 'a');
}

static void	turks_migration(t_elem **stack_a, t_elem **stack_b, bool dest_arg_i)
{
	t_elem	**migr_src;
	t_elem	**migr_dest;

	if (dest_arg_i)
	{
		migr_src = stack_a;
		migr_dest = stack_b;
	}
	else
	{
		migr_src = stack_b;
		migr_dest = stack_a;
	}
	while (*migr_src)
	{
		if (dest_arg_i && (((*stack_a)->next->next == (*stack_a)->prev) || is_sorted(stack_a)))
			break ;
		do_cheapest_rotation(stack_a, stack_b, dest_arg_i);
		push(migr_src, migr_dest, 'a' + dest_arg_i);
	}
}

static void	turks_final_a_rotation(t_elem **stack_a)
{
	int		smallest;
	int		largest;

	smallest_and_largest(stack_a, &smallest, &largest);
	if (num_index(stack_a, smallest) < (size(stack_a) / 2))
	{
		while ((*stack_a)->num != smallest)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->num != smallest)
			rev_rotate(stack_a, 'a');
	}	
}

void	turks(t_elem **stack_a, t_elem **stack_b)
{
	size_t	length;

	length = size(stack_a);
	if (length <= 3)
	{
		sort_up_to_three(stack_a, 'a');
		return ;
	}
	turks_init(stack_a, stack_b, length);
	turks_migration(stack_a, stack_b, 1);
	if (!is_sorted(stack_a))
		sort_up_to_three(stack_a, 'a');
	turks_migration(stack_a, stack_b, 0);
	turks_final_a_rotation(stack_a);
}
