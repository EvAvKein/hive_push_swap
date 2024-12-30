/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:54:21 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/30 20:10:20 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SEQUENCE EXAMPLE:
//
// 1 2 3 4 5
//				5->2
//				1<-3
//				5<-2
//				1->3
//				2->1
//				2<-1
// 2 1 3 4 5
void	swap(t_elem **stack, char name)
{
	if ((*stack)->next->next == *stack)
		*stack = (*stack)->next;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->next->prev = (*stack);
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev->next->next = (*stack);
		(*stack)->prev = (*stack)->prev->next;
		*stack = (*stack)->prev;
	}
	if (name)
		ft_printf("s%c\n", name);
}

void	swap_both(t_elem **stack1, t_elem **stack2)
{
	swap(stack1, '\0');
	swap(stack2, '\0');
	ft_printf("ss\n");
}
