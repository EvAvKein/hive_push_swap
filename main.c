/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:33:50 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/29 19:12:31 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_elem **stack, char name)
{
	t_elem	*initial;

	if (!stack || !*stack)
	{
		ft_printf("Stack %c empty\n", name);
		ft_printf("---\n");
		return ;
	}
	ft_printf("Stack %c:\n", name);
	initial = *stack;
	ft_printf("%d\n", (*stack)->num);
	*stack = (*stack)->next;
	while (*stack != initial)
	{
		ft_printf("%d\n", (*stack)->num);
		(*stack) = (*stack)->next;
	}
}

void	print_stacks(t_elem **stack1, char name1, t_elem **stack2, char name2)
{
	ft_printf("---\n");
	print_stack(stack1, name1);
	ft_printf("---\n");
	print_stack(stack2, name2);
	ft_printf("---\n");
}

int	main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = args_to_list(argc, argv);
	if (!stack_a || args_dupe_check(&stack_a))
	{
		stack_clear(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	if (is_sorted(&stack_a))
		return (0);
	turks(&stack_a, &stack_b);
	print_stacks(&stack_a, 'a', &stack_b, 'b');
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
