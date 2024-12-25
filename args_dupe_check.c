/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_dupe_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:38:20 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/25 13:46:36 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	args_dupe_check(t_elem **stack)
{
	t_elem	*initial;
	t_elem	*current;
	t_elem	*check;

	initial = *stack;
	current = *stack;
	while (current->next != initial)
	{
		check = current->next;
		while (check != initial)
		{
			if (current->num == check->num)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
