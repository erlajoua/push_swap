/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooftop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:59 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/01 12:50:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		get_movs(t_algo *algo)
{
	int middle;
	int first_movs;
	int second_movs;

	middle = algo->a_len / 2;
	first_movs = algo->first_pos;
	if (algo->first_pos > middle)
		first_movs = (algo->a_len - algo->first_pos) * -1;
	second_movs = algo->a_len - algo->second_pos * -1;
	if (algo->second_pos < middle)
		second_movs = algo->second_pos;
	if (first_movs < second_movs)
		return (first_movs);
	return (second_movs);
}

void	ft_rooftop(t_list **a, t_algo *algo)
{
	int top_movs;

	top_movs = get_movs(algo);
	if (top_movs < 0)
	{
		algo->ret += -top_movs;
		while (top_movs++ < 0)
			rra(a, algo->display);
	}
	else
	{
		algo->ret += top_movs;
		while (top_movs-- > 0)
			ra(a, algo->display);
	}
}
