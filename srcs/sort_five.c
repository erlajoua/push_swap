/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:27:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 15:13:12 by erlajoua         ###   ########.fr       */
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

void	sort_five(t_list **a, t_list **b)
{
	int		ref;
	int		j;
	t_list	*top;
	t_list	*new;

	j = 2;
	pb(a, b);
	pb(a, b);
	sort_three(a);
	print_list(a, b);
	if ((*b)->data < (*b)->next->data)
		ft_swap(&((*b)->data), &((*b)->next->data));
	top = *b;
	print_list(a, b);
	while ((top) || j)
	{
		new = *a;
		ref = accept(a, top->data);
		if (new->data == ref)
		{
			pa(a, b);
			j--;
			top = top->next;
		}
		else
			ra(a);
	}
	int *tab = list_to_tab(a);
	int len = list_len(a);
	int index_min = find_index_min(tab, len);
	while (index_min != 0)
	{
		ra(a);
		index_min--;
	}
	free(tab);
}
