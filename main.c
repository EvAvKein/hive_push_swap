/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:33:50 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/25 21:26:23 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stack(t_elem **stack, char name)
{
	t_elem	*initial;

	ft_printf("---\n");
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
	ft_printf("---\n");
}

int	main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = args_to_list(argc, argv);
//	if (!stack_a)
//		ft_printf("Listmaking issue\n");
//	if (args_dupe_check(&stack_a))
//		ft_printf("Dupes found\n");
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
	print_stack(&stack_a, 'a');
	print_stack(&stack_b, 'b');
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

	//push(&stack_a, &stack_b, 'b');
	//swap(&stack_a, 'a');
	//rotate(&stack_a, 'a');
	//rev_rotate(&stack_a, 'a');
	//ft_printf("Sorted: %i\n", is_sorted(&stack_a));
	
	//print_stack(&stack_a, 'a');
	//ft_printf("---\n");
	
	//ft_printf("---\n");
	//print_stack(&stack_a, 'a');
	//ft_printf("---\n");
	//print_stack(&stack_b, 'b');
