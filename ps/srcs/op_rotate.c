/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:33:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/03 11:33:58 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rb(t_list **b, int option)
{
	t_list	*last;
	t_list	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	last = init_list((*b)->data);
	if (!last)
		return ;
	remove_top(b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->prev = tmp;
	if (option == SHOW)
		printf("rb\n");
}

void	ra(t_list **a, int option)
{
	t_list	*last;
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	last = init_list((*a)->data);
	if (!last)
		return ;
	remove_top(a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->prev = tmp;
	if (option == SHOW)
		printf("ra\n");
}

void	rr(t_list **a, t_list **b, int option)
{
	ra(a, HIDE);
	rb(b, HIDE);
	if (option == SHOW)
		printf("rr\n");
}
