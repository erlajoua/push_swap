/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:27:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 10:51:46 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_five(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	print_list(a, b);
	if ((*b)->data < (*b)->next->data)
		ft_swap(&((*b)->data), &((*b)->next->data));
	pa(a, b);
	pa(a, b);
}
