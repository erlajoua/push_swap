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

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (option == 1)
		printf("rra\n");
}

void	rrb(t_list **b, int option)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
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
