/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:08:03 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 15:39:21 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rb(t_list **b)
{
	t_list	*last;
	t_list	*tmp;

	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	last = init_list((*b)->data);
	if (!last)
		return ;
	remove_top(b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	printf("rb\n");
}

void	ra(t_list **a)
{
	t_list	*last;
	t_list	*tmp;

	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	last = init_list((*a)->data);
	if (!last)
		return ;
	remove_top(a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	printf("ra\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	printf("rrr\n");
}
