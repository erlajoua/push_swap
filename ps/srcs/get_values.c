/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:18:38 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 08:41:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	mov_sup(int movs, t_list **b, t_algo *algo)
{
	int common;
	int pos;

	pos = get_pos(b, algo->h_first);
	if (pos == -1)
		pos = get_bigger_pos(b);
	if (pos > algo->b_len / 2)
		pos = pos - algo->b_len;
	if (pos > 0)
	{
		common = min(movs, pos);
		algo->rr = common;
		if (pos == common)
			algo->ra = movs - common;
		else
			algo->rb = pos - common;
	}
	else
	{
		algo->ra = movs;
		algo->rrb = -pos;
	}
}

void	mov_inf(int movs, t_list **b, t_algo *algo)
{
	int common;
	int pos;

	movs = -movs;
	pos = get_pos(b, algo->h_first);
	//printf("pos0: %d\n", pos);
	if (pos == -1)
		pos = get_bigger_pos(b);
	//printf("pos1: %d\n", pos);
	if (pos > algo->b_len / 2)
		pos = pos - algo->b_len;
	//printf("pos2: %d, movs : %d\n", pos, movs);
	if (pos < 0)
	{
		pos = -pos;
		common = min(movs, pos);
		algo->rrr = common;
		if (pos == common)
			algo->rra = movs - common;
		else
			algo->rrb = pos - common;
	}
	else
	{
		algo->rb = pos;
		algo->rra = movs;
	}
}

void	get_values(t_list **b, t_algo *algo)
{
	int movs;

	movs = get_movs(algo);
	if (movs >= 0)
		mov_sup(movs, b, algo);
	else if (movs < 0)
		mov_inf(movs, b, algo);
}
