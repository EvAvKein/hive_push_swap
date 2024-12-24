/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:42:52 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/23 17:08:16 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_full/libft_full.h"

// The structure of each element in the stack
typedef struct s_elem
{
	struct s_elem	*prev;
	int				num;
	struct s_elem	*next;
}					t_elem;

// Convert args to a linked list where each element is the above struct
t_elem	*args_to_list(int argc, char **argv);

// Scan list for duplicate values and return boolean accordingly
int		args_dupe_check(t_elem **stack);

// Free and delete entire stack
void	*stack_clear(t_elem **stack);

// Swap the first 2 elements at the top of the stack
void	swap(t_elem **stack, char name);
void	swap_both(t_elem **stack1, t_elem **stack2);

// Take the first element at the top of stack1 and put it at the top of stack2
void	push(t_elem **stack1, t_elem **stack2, char stack2_name);

// Shift up all elements of the stack by 1 (first element becomes the last)
void	rotate(t_elem **stack, char name);
void	rotate_both(t_elem **stack1, t_elem **stack2);

// Shift down all elements of the stack by 1 (last element becomes the first)
void	rev_rotate(t_elem **stack, char name);
void	rev_rotate_both(t_elem **stack1, t_elem **stack2);

// Boolean about whether the stack is sorted
int		is_sorted(t_elem **stack);

#endif
