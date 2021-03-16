/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:05:39 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/08 18:38:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*curr;

	curr = *a;
	tmp = NULL;
	while (curr)
	{
		tmp = curr->prev;
		curr->prev = curr->next;
		curr->next = tmp;
		curr = curr->prev;
	}
	if (tmp)
		*a = tmp->prev;
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*curr;

	tmp = NULL;
	curr = *b;
	while (curr)
	{
		tmp = curr->prev;
		curr->prev = curr->next;
		curr->next = tmp;
		curr = curr->prev;
	}
	if (tmp)
		*b = tmp->prev;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
