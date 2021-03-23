/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/23 17:25:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	init_algo(t_algo *algo, t_list **a, int size, int chunksize)
{
	//int save;

	algo->ret = 0;
	algo->sort = sort_list(a, size);
	//save = algo->chunk_size / 5;
	//algo->chunk_size = save;
	algo->chunk_size = chunksize;
	algo->chunk_nb = size / algo->chunk_size;
	algo->current = 1;
}

void	apply_rotates(t_list **a, t_list **b, t_algo *algo)
{
	while (algo->rr-- > 0)
		rr(a, b, algo->display);
	while (algo->ra-- > 0)
		ra(a, algo->display);
	while (algo->rb-- > 0)
		rb(b, algo->display);
	while (algo->rr-- > 0)
		rrr(a, b, algo->display);
	while (algo->rra-- > 0)
		rra(a, algo->display);
	while (algo->rrb-- > 0)
		rrb(b, algo->display);
	pb(a, b, algo->display);
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

int		algo(t_list **a, t_list **b, int size, int chunksize, int display)
{
	t_algo	algo;
	int		i;

	i = 0;
	init_algo(&algo, a, size, chunksize);
	algo.display = display;
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
			algo.ret += 1 + algo.ra + algo.rb + algo.rra + algo.rrb + algo.rr + algo.rrr;
			apply_rotates(a, b, &algo);
			i++;
		}
		algo.ret += swap_to_a(a, b, &algo);
	}
	//printf("algo.ret = %d\n", algo.ret);
	return (algo.ret);
}
