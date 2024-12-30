/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:09:51 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/30 17:34:30 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_elem **stack, char name)
{
	*stack = (*stack)->next;
	if (name)
		ft_printf("r%c\n", name);
}

void	rotate_both(t_elem **stack1, t_elem **stack2)
{
	rotate(stack1, '\0');
	rotate(stack2, '\0');
	ft_printf("rr\n");
}

void	rev_rotate(t_elem **stack, char name)
{
	*stack = (*stack)->prev;
	if (name)
		ft_printf("rr%c\n", name);
}

void	rev_rotate_both(t_elem **stack1, t_elem **stack2)
{
	rev_rotate(stack1, '\0');
	rev_rotate(stack2, '\0');
	ft_printf("rrr\n");
}
