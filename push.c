/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:09:15 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/30 20:08:56 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_operation(t_elem **stack1, t_elem **stack2)
{
	t_elem	*moved;

	moved = *stack1;
	if ((*stack1)->next == *stack1)
		*stack1 = NULL;
	else
	{
		(*stack1)->prev->next = (*stack1)->next;
		(*stack1)->next->prev = (*stack1)->prev;
		*stack1 = (*stack1)->next;
	}
	if (!*stack2)
	{
		moved->next = moved;
		moved->prev = moved;
	}
	else
	{
		moved->next = *stack2;
		moved->prev = (*stack2)->prev;
		(*stack2)->prev->next = moved;
		(*stack2)->prev = moved;
	}
	*stack2 = moved;
}

void	push(t_elem **stack1, t_elem **stack2, char stack2_name)
{
	push_operation(stack1, stack2);
	ft_printf("p%c\n", stack2_name);
}
