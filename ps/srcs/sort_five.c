/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:34:15 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/03 11:34:16 by erlajoua         ###   ########.fr       */
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
	return (min[1]);
}

void	apply_five(t_list **a, int pos)
{
	int a_len;

	a_len = list_len(a);
	if (pos > (a_len / 2))
		pos = pos - a_len;
	if (pos < 0)
		while (pos++ < 0)
			rra(a, SHOW);
	else
		while (pos-- > 0)
			ra(a, SHOW);
}

void	sort_five(t_list **a, t_list **b)
{
	int pos;

	pb(a, b, SHOW);
	if (list_len(a) == 4)
		pb(a, b, SHOW);
	sort_three(a);
	while ((*b) != NULL)
	{
		pos = get_rpos(a, (*b)->data);
		if (pos == -1)
		{
			pos = get_lower_pos(a);
			apply_five(a, pos);
			pa(a, b, SHOW);
			if ((*b) && ((*b)->data > (*a)->data))
				rra(a, SHOW);
		}
		else
		{
			apply_five(a, pos);
			pa(a, b, SHOW);
		}
	}
	pos = get_lower_pos(a);
	apply_five(a, pos);
}
