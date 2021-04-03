/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooftop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:33:30 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/03 11:33:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		get_movs(t_algo *algo)
{
	int first_movs;
	int second_movs;

	first_movs = algo->first_pos;
	second_movs = algo->a_len - algo->second_pos;
	if (first_movs < second_movs)
		return (first_movs);
	second_movs *= -1;
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
