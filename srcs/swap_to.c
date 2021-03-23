/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:18:51 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/23 17:20:51 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		swap_to_a(t_list **a, t_list **b, t_algo *algo)
{
	int bp;
	int b_len;
	int movs;
	int ret;

	bp = get_bigger_pos(b);
	b_len = list_len(b);
	movs = bp;
	ret = 0;
	if (bp > b_len / 2)
		movs = b_len - bp;
	while (movs-- > 0)
	{
		if (bp <= b_len / 2)
			rb(b, algo->display);
		else
			rrb(b, algo->display);
		ret++;
	}
	while (*b != NULL)
	{
		pa(a, b, algo->display);
		ret++;
	}
	return (ret);
}
