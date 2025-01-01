/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:34:47 by ekeinan           #+#    #+#             */
/*   Updated: 2025/01/01 16:48:17 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_instruction(t_elem **a, t_elem **b, char *s, bool *err)
{
	if (!ft_strncmp(s, "pb\n", 4))
		push(a, b, 0);
	else if (!ft_strncmp(s, "pa\n", 4))
		push(b, a, 0);
	else if (!ft_strncmp(s, "sa\n", 4))
		swap(a, 0);
	else if (!ft_strncmp(s, "sb\n", 4))
		swap(b, 0);
	else if (!ft_strncmp(s, "ss\n", 4))
		swap_both(a, b, 0);
	else if (!ft_strncmp(s, "ra\n", 4))
		rotate(a, 0);
	else if (!ft_strncmp(s, "rb\n", 4))
		rotate(b, 0);
	else if (!ft_strncmp(s, "rr\n", 4))
		rotate_both(a, b, 0);
	else if (!ft_strncmp(s, "rra\n", 5))
		rev_rotate(a, 0);
	else if (!ft_strncmp(s, "rrb\n", 5))
		rev_rotate(b, 0);
	else if (!ft_strncmp(s, "rrr\n", 5))
		rev_rotate_both(a, b, 0);
	else
		*err = 1;
}

static void	free_and_write(t_elem **stack1, t_elem **stack2, int fd, char *text)
{
	stack_clear(stack1);
	stack_clear(stack2);
	write(fd, text, ft_strlen(text));
}

static void	validate(t_elem **stack_a, t_elem **stack_b)
{
	char	*line;
	bool	err;	

	err = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			if (is_sorted(stack_a) && !*stack_b)
				return (free_and_write(stack_a, stack_b, 1, "OK\n"));
			return (free_and_write(stack_a, stack_b, 1, "KO\n"));
		}
		do_instruction(stack_a, stack_b, line, &err);
		if (err)
			return (free_and_write(stack_a, stack_b, 2, "Error\n"));
		free(line);
	}
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
		return (1);
	}
	stack_b = NULL;
	validate(&stack_a, &stack_b);
	return (0);
}
