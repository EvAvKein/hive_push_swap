/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:42:52 by ekeinan           #+#    #+#             */
/*   Updated: 2024/12/28 20:58:49 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_full/libft_full.h"
# include "stdbool.h"

// The structure of each element in the stack
typedef struct s_elem
{
	struct s_elem	*prev;
	int				num;
	struct s_elem	*next;
}					t_elem;

// DEBUGGING
void	print_stack(t_elem **stack, char name);

// Convert args to a linked list where each element is the above struct
t_elem	*args_to_list(int argc, char **argv);

// Scan list for duplicate values and return boolean accordingly
bool	args_dupe_check(t_elem **stack);

// Free and delete entire stack
void	*stack_clear(t_elem **stack);

// Execute the entire Turks sorting algorithm
void	turks(t_elem **stack_a, t_elem **stack_b);

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

// Return whether the stack is sorted
bool	is_sorted(t_elem **stack);

// Return the size of the stack
size_t	size(t_elem **stack);

// Return the index of the number inside the stack
size_t	num_index(t_elem **stack, int num);

// Return the index where the new number should be prepended to be sorted
size_t	index_for_prepend(t_elem **stack, int new, bool descending);

// Assign the smallest and largest ints in stack to the int pointers
void	smallest_and_largest(t_elem **stack, int *smallest, int *largest);

// Return the number of rotations needed to reach the num
// The by_bool variant uses the final arg to determine whether both reverse
// The by_index variant uses the final arg to determine which one reverses
size_t	rotations_rev_by_bool(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_and_push_bools);
size_t	rotations_counter_by_index(
		t_elem **stack_a, t_elem **stack_b, int num, int rev_and_push_bools);

// Return the least amount of rotations necessary for a worthwhile push
size_t	find_cheapest_rotation(
		t_elem **stack_a, t_elem **stack_b, bool push_arg_i);

// If new is lower than lowest, set lowest to new (created due to norm)
void    set_if_lower(ssize_t *lowest, ssize_t new);

// Execute the cheapest rotation possible for a worthwhile push
void	do_cheapest_rotation(t_elem **stack_a, t_elem **stack_b, bool push_arg_i);

#endif
