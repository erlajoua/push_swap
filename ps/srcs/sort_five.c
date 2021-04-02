/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:27:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/01 13:14:37 by erlajoua         ###   ########.fr       */
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

int		accept(t_list **a, int ref)
{
	t_list	*tmp;
	int		*tab;
	int		accept;
	int		len;

	tmp = *a;
	tab = list_to_tab(a);
	len = list_len(a);
	accept = find_index_min(tab, len);
	while (tmp)
	{
		if ((tmp->data > accept) && (tmp->data > ref))
		{
			free(tab);
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	free(tab);
	return (accept);
}

void	end_sort_five(t_list **a)
{
	int *tab;
	int len;
	int index_min;

	tab = list_to_tab(a);
	len = list_len(a);
	index_min = find_index_min(tab, len);
	while (index_min != 0)
	{
		ra(a, 0);
		index_min--;
	}
	free(tab);
}

void	five_loop(t_list **a, t_list **b, int j)
{
	int		ref;
	t_list	*top;
	t_list	*new;

	top = *b;
	while ((top) || j)
	{
		new = *a;
		ref = accept(a, top->data);
		if (new->data == ref)
		{
			pa(a, b, 1);
			j--;
			top = top->next;
		}
		else
			ra(a, 1);
	}
}

void	sort_five(t_list **a, t_list **b, int ac)
{
	int pos;
	int a_len;

	pb(a, b, 0);
	if (ac - 1 == 5)
		pb(a, b, 0);
	sort_three(a);
	while ((*b) != NULL)
	{
		pos = get_rpos(a, (*b)->data);
		a_len = list_len(a);
		if (pos == -1)
		{
			pa(a, b, SHOW);
			if ((*b)->data > (*a)->data)
				rra(a, SHOW);
		}
		else
		{
			if (pos > (a_len / 2))
				pos = pos - a_len;
			if (pos < 0)
				while (pos++ < 0)
					rra(a, SHOW);
			else
				while (pos-- > 0)
					ra(a, SHOW);
		}
		pa(a, b, SHOW);
	}
	pos = get_lower_pos(a);
	a_len = list_len(a);
	if (pos > (a_len / 2))
		pos = pos - a_len;
	printf("pos = %d\n", pos);
	if (pos < 0)
		while (pos++ < 0)
			rra(a, SHOW);
	else
		while (pos-- > 0)
			ra(a, SHOW);
	print_list(a, b);
}
