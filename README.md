# PUSH_SWAP

My 5th project at 42 Network's Hive Helsinki 🐝

Sorting a list with a limited set of valid operations!

> [!TIP]
> If you're at a 42 school and doing this project: It's genuinely so much better to ask fellow students instead of reading online solutions ✨

---

## Description

The assignment is to make a program which sorts a given list of number, under the following rules:
- You have 2 stacks called a and b. At the beginning, stack a contains a random amount of numbers which cannot be duplicates. Stack b is empty.
- The goal is printing the steps necessary to sort the numbers in ascending order into stack a, using the following operations:
	- `sa` (swap a): Swap the first 2 elements at the top of stack a.  
		Do nothing if there is only one or no elements.
	- `sb` (swap b): Swap the first 2 elements at the top of stack b.  
		Do nothing if there is only one or no elements.
	- `ss` : `sa` and `sb` at the same time.  
	- `pa` (push a): Take the first element at the top of b and put it at the top of a.  
		Do nothing if b is empty.
	- `pb` (push b): Take the first element at the top of a and put it at the top of b.  
		Do nothing if a is empty.i
	- `ra` (rotate a): Shift up all elements of stack a by 1.  
		The first element becomes the last one.
	- `rb` (rotate b): Shift up all elements of stack b by 1.  
		The first element becomes the last one.
	- `rr` : `ra` and `rb` at the same time.
	- `rra` (reverse rotate a): Shift down all elements of stack a by 1.  
		The last element becomes the first one.
	- `rrb` (reverse rotate b): Shift down all elements of stack b by 1.  
		The last element becomes the first one.  
	- `rrr` : `rra` and `rrb` at the same time.
- To pass with 80/100 score, always sort 100 numbers in fewer than 700 operations.  
To pass with 100/100 score, always sort 500 numbers in fewer than 5500 operations.  

In the assignment's page, we are provided a program to validate whether the list is sorted. For the bonus (optional) part of the project, the assignment is to recreate that validation program.

> [!NOTE]
> The efficiency requirements are tight enough that earlier students gave up after months of trying to invent sufficient algorithms or adjust common ones.
> Our student cohort got recommended to pick between either Radix Sort or the [Turks](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) algorithm (the one I reimplemented) invented specifically for this assignment.

> A lot of us students found this particular project to be relatively contrived and not educational. I took the liberty to have fun in the assignment by writing particular parts in an excessively 'clever'/obtuse way - e.g. `index_to_prepend` where I used type-casting and bit operations to hold two values in one variable, to comply with the school's 5 variable declaration limit. The majority of the code should be readable enough though!

---

## Usage

> [!NOTE]
> Code was written and tested for Linux (using Hive's Ubuntu iMacs)

### Sorter
- Compile by running `make`
- Run `./push_swap` followed by a random set of unsorted numbers (within the size limit of a C `int`)

### Checker
- Compile by running `make bonus`
- Run `./checker_ekeinan` followed by the numbers. Sorting instructions are received on the standard input - you can, for example:
	- Pipe the sorter's output into the checker
	- Redirect from a file into the checker
	- Type the operations in the terminal (terminated by `ctrl+d`)

---

## Credits

- [Eve Keinan](https://github.com/EvAvKein)
