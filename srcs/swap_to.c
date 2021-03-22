/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:18:51 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/22 19:18:52 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_to_b(t_list **a, t_list **b)
{
	int pos;
	int b_len;
	int	movs;

	if (*b && (*b)->next != NULL)
	{
		if ((pos = get_pos(b, (*a)->data)) == -1)
			pos = get_bigger_pos(b);
		b_len = list_len(b);
		movs = pos;
		if (pos > b_len / 2)
			movs = b_len - pos;
		while (movs-- > 0)
		{
			if (pos <= b_len / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
	pb(a, b, 1);
}

void	swap_to_a(t_list **a, t_list **b)
{
	int bp;
	int b_len;
	int movs;

	bp = get_bigger_pos(b);
	b_len = list_len(b);
	movs = bp;
	if (bp > b_len / 2)
		movs = b_len - bp;
	while (movs-- > 0)
	{
		if (bp <= b_len / 2)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	while (*b != NULL)
		pa(a, b, 1);
}
