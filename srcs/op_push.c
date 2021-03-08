/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:50:59 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/08 09:51:00 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	push_front(a, (*b)->data);
	remove_top(b);
}

void	pb(t_list **a, t_list **b)
{
	push_front(b, (*a)->data);
	remove_top(a);
}
