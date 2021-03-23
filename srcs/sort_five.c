/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:27:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/23 17:28:48 by erlajoua         ###   ########.fr       */
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
	pb(a, b, 0);
	if (ac - 1 == 5)
		pb(a, b, 0);
	sort_three(a);
	print_list(a, b);
	if (ac - 1 == 5 && ((*b)->data < (*b)->next->data))
		ft_swap(&((*b)->data), &((*b)->next->data));
	if (ac - 1 == 5)
		five_loop(a, b, 2);
	else
		five_loop(a, b, 1);
	end_sort_five(a);
}
