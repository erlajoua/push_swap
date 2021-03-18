/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:50:55 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 18:56:22 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		is_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	parsing(int ac, char **av, t_list **a, t_list **b)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < ac)
	{
		push_back(a, ft_atoi(av[i]));
		i++;
	}
	/*if (ac - 1 == 3)
		sort_three(a);
	else if (ac - 1 == 5)
		sort_five(a, b);
	else
		sort_general(a, b);*/
	print_list(a, b);
	rra(a, 0);
	print_list(a, b);
	rra(a, 0);
	print_list(a, b);
	rra(a, 0);
	print_list(a, b);
}
