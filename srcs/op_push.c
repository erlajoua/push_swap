/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:50:59 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 18:45:08 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pa(t_list **a, t_list **b, int option)
{
	if (*b == NULL)
		return ;
	if (*a == NULL)
		*a = init_list((*b)->data);
	else
		push_front(a, (*b)->data);
	remove_top(b);
	if (option == 1)
		printf("pa\n");
}

void	pb(t_list **a, t_list **b, int option)
{
	if (*a == NULL)
		return ;
	if (*b == NULL)
		*b = init_list((*a)->data);
	else
		push_front(b, (*a)->data);
	remove_top(a);
	if (option == 1)
		printf("pb\n");
}
