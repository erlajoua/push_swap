/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/22 20:43:58 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	init_algo(t_algo *algo, t_list **a, int size)
{
	int save;

	algo->chunk_size = size;
	algo->sort = sort_list(a, size);
	save = algo->chunk_size / 5;
	algo->chunk_size = save;
	algo->chunk_nb = size / save;
	algo->current = 1;
}

void	apply_rotates(t_list **a, t_list **b, t_algo *algo)
{
	while (algo->rr-- > 0)
		rr(a, b, 1);
	while (algo->ra-- > 0)
		ra(a, 1);
	while (algo->rb-- > 0)
		rb(b, 1);
	while (algo->rr-- > 0)
		rrr(a, b, 1);
	while (algo->rra-- > 0)
		rra(a, 1);
	while (algo->rrb-- > 0)
		rrb(b, 1);
	pb(a, b, 1);
}

void	init_loop(t_algo *algo)
{
	algo->ra = 0;
	algo->rb = 0;
	algo->rra = 0;
	algo->rrb = 0;
	algo->rr = 0;
	algo->rrr = 0;
}

void	algo(t_list **a, t_list **b, int size)
{
	t_algo	algo;
	int		i;

	i = 0;
	init_algo(&algo, a, size);
	if (size > 5)
	{
		while (*a != NULL)
		{
			init_loop(&algo);
			algo.a_len = list_len(a);
			algo.b_len = list_len(b);
			find_hold(a, &algo);
			if ((*b) && (*b)->next)
				get_values(b, &algo);
			else
				ft_rooftop(a, &algo);
			apply_rotates(a, b, &algo);
			i++;
		}
		swap_to_a(a, b);
	}
}
