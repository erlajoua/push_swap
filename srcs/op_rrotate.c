/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:05:39 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 18:59:49 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_list **a, int option)
{
	t_list	*tmp;
	t_list	*newelem;
	t_list	*pro;

	tmp = *a;
	if (!(tmp->next))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	pro = tmp;
	pro->prev->next = NULL;
	newelem = init_list(tmp->data);
	free(tmp);
	(*a)->prev = newelem;
	newelem->next = (*a);
	*a = newelem;
	if (option == 1)
		printf("rra\n");
}

void	rrb(t_list **b, int option)
{
	t_list	*tmp;
	t_list	*newelem;

	tmp = *b;
	if (!(tmp->next))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	newelem = init_list(tmp->data);
	free(tmp);
	(*b)->prev = newelem;
	newelem->next = (*b);
	*b = newelem;
	if (option == 1)
		printf("rrb\n");
}

void	rrr(t_list **a, t_list **b, int option)
{
	rra(a, 0);
	rrb(b, 0);
	if (option == 1)
		printf("rrr\n");
}
