/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:09:15 by ekeinan           #+#    #+#             */
/*   Updated: 2025/01/14 10:17:23 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_operation(t_elem **stack1, t_elem **stack2)
{
	*stack1 = (*stack1)->next;
	(*stack1)->prev->next = *stack2;
	*stack2 = (*stack1)->prev;
	if ((*stack1)->prev == *stack1)
		*stack1 = NULL;
	else
	{
		(*stack1)->prev = (*stack1)->prev->prev;
		(*stack1)->prev->next = *stack1;
	}
	if (!(*stack2)->next)
	{
		(*stack2)->next = *stack2;
		(*stack2)->prev = *stack2;
	}
	else
	{
		(*stack2)->prev = (*stack2)->next->prev;
		(*stack2)->next->prev = *stack2;
		(*stack2)->prev->next = *stack2;
	}
}

void	push(t_elem **stack1, t_elem **stack2, char stack2_name)
{
	if (!stack1 || !*stack1)
		return ;
	push_operation(stack1, stack2);
	if (stack2_name)
		ft_printf("p%c\n", stack2_name);
}
