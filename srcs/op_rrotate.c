/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:05:39 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 13:41:43 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*newelem;
	t_list	*pro;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	printf("arrivee rra\n");
	pro = tmp->prev;
	pro->next = NULL;
	newelem = init_list(tmp->data);
	free(tmp);
	(*a)->prev = newelem;
	newelem->next = (*a);
	*a = newelem;
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*newelem;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	newelem = init_list(tmp->data);
	free(tmp);
	(*b)->prev = newelem;
	newelem->next = (*b);
	*b = newelem;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
