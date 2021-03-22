/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:27:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/22 19:14:27 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		accept(t_list **a, int ref)
{
	t_list	*tmp;
	int		accept;

	tmp = *a;
	accept = -2147483648;
	while (tmp)
	{
		if ((tmp->data > accept) && (tmp->data > ref))
			return (tmp->data);
		tmp = tmp->next;
	}
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

void	five_loop(t_list *top, t_list **a, t_list **b)
{
	int		j;
	int		ref;
	t_list	*new;

	j = 2;
	while ((top) || j)
	{
		new = *a;
		ref = accept(a, top->data);
		if (new->data == ref)
		{
			pa(a, b, 0);
			j--;
			top = top->next;
		}
		else
			ra(a, 0);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	t_list	*top;

	pb(a, b, 0);
	pb(a, b, 0);
	sort_three(a);
	print_list(a, b);
	if ((*b)->data < (*b)->next->data)
		ft_swap(&((*b)->data), &((*b)->next->data));
	top = *b;
	five_loop(top, a, b);
	end_sort_five(a);
}
