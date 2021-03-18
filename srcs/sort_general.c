/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:54:58 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 18:53:12 by erlajoua         ###   ########.fr       */
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
		tab = list_to_tab(a);
		index_min = find_index_min(tab, len);
		while (index_min != 0)
		{
			ra(a, 0);
			index_min--;
		}
		pb(a, b, 0);
		free(tab);
	}
	len = list_len(b);
	while (len != 0)
	{
		pa(a, b, 0);
		len--;
	}
}
