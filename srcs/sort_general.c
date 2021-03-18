/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:54:58 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 13:37:42 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		find_index_min(int *tab, int len)
{
	int i;
	int min[2];

	min[0] = 0;
	min[1] = tab[0];
	i = 0;
	while (i < len)
	{
		if (tab[i] < min[1])
		{
			min[0] = i;
			min[1] = tab[i];
		}
		i++;
	}
	return (min[0]);
}

void	sort_general(t_list **a, t_list **b)
{
	int		len;
	int		*tab;
	int		op;
	int		index_min;

	while (*a)
	{
		op = 0;
		len = list_len(a);
		printf("LEN : %d\n", len);
		tab = list_to_tab(a);
		index_min = find_index_min(tab, len);
		printf("undex_min : %d\n", index_min);
		if (index_min > (len / 2))
		{
			op = 1;
			index_min = len - index_min;
		}
		while (index_min != 0)
		{
			if (op == 1)
			{
				printf("before rra\n");
				print_list(a, b);
				rra(a);
				print_list(a, b);
				printf("after rra\n");
			}
			else
				ra(a);
			index_min--;
		}
		pb(a, b);
		print_list(a, b);
		free(tab);
	}
	len = list_len(b);
	while (len != 0)
	{
		pa(a, b);
		len--;
	}
}
