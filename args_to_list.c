/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:35:42 by ekeinan           #+#    #+#             */
/*   Updated: 2025/01/27 13:54:10 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int *err)
{
	*err = 1;
	return (0);
}

static int	ft_atoi_strict(char *str, int *err)
{
	size_t	i;
	int		num;
	int		is_negative;

	i = 0;
	num = 0;
	if (!str)
		return (error(err));
	if (!ft_strncmp(str, "-2147483648", 12))
		return (-2147483648);
	is_negative = (str[i] == '-');
	if ((!(*str >= '0' && *str <= '9')
			&& !((*str == '-' || *str == '+') && ++i)) || !str[i])
		return (error(err));
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - 48);
		if (num < 0)
			return (error(err));
	}
	if (str[i])
		return (error(err));
	if (is_negative)
		num = 0 - num;
	return (num);
}

static t_elem	*ft_elemnew(int num, int *err)
{
	t_elem	*new;

	if (*err)
		return (NULL);
	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->num = num;
	new->next = NULL;
	return (new);
}

static t_elem	*arr_to_list(char **arr, size_t length)
{
	size_t	i;
	t_elem	*list;
	t_elem	*last_elem;
	t_elem	*new_elem;
	int		err;

	i = 0;
	err = 0;
	list = ft_elemnew(ft_atoi_strict(arr[i++], &err), &err);
	if (!list)
		return (NULL);
	last_elem = list;
	while (i < length)
	{
		new_elem = ft_elemnew(ft_atoi_strict(arr[i++], &err), &err);
		if (!new_elem)
			return (stack_clear(&list));
		last_elem->next = new_elem;
		new_elem->prev = last_elem;
		last_elem = new_elem;
	}
	last_elem->next = list;
	list->prev = last_elem;
	return (list);
}

t_elem	*args_to_list(int argc, char **argv)
{
	char	**arg_arr;
	t_elem	*list;
	size_t	len;

	arg_arr = NULL;
	if (ft_strchr(argv[1], ' '))
	{
		if (argc > 2 || !argv[1][0])
			return (NULL);
		arg_arr = ft_split(argv[1], ' ');
		if (!arg_arr)
			return (NULL);
		len = 0;
		while (arg_arr[len])
			len++;
		list = arr_to_list(arg_arr, len);
		while (*arg_arr)
			free(*(arg_arr++));
		free(arg_arr - len);
	}
	else
		list = arr_to_list(&argv[1], argc - 1);
	return (list);
}
