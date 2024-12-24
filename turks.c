/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:36:26 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/24 20:55:25 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	easy_sort(t_elem **stack, char name)
{
	size_t	length;

	length = size(stack);
	if (length == 2)
	{
		rotate(stack, name);
	}
	if (length == 3)
	{
		sort_three(stack, name);
		return (1);
	}
	return (0);
}

/*
void	turks_migration_to_b(t_elem **stack_a, t_elem **stack_b)
{
	size_t	size;
	
	i = ;

	while ((*stack_a)->next->next != (*stack_b)->prev)
	{
		smallest_and_largest(stack_a, &sm_a, &lg_a);
		smallest_and_largest(stack_b, &sm_b, &lg_b);
		
	}
}*/

void	turks_init(t_elem **stack_a, t_elem **stack_b, size_t length)
{
	push(stack_a, stack_b, 'b');
	if (length > 4)
	{
		push(stack_a, stack_b, 'b');
		if (is_sorted(stack_b))
			rotate(stack_b, 'b');
	}
	if (!is_sorted(stack_a))
		easy_sort(stack_a);
}

void	turks(t_elem **stack_a, t_elem **stack_b)
{
	size_t	length;

	length = size(stack_a);
	if (length <= 3)
	{
		easy_sort(stack_a, 'a');
		return ;
	}
	turks_init(stack_a, stack_b, length);
//	if ((*stack_a)->next == (*stack_a)->prev)
//		return turks_for_four_past_init(t_elem **stack_a, t_elem **stack_b);
	turks_migration_to_b(stack_a, stack_b);
	while ((*stack_a)->next->)

}
