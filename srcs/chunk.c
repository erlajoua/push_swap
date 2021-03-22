/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:18 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/22 20:35:24 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		is_in_chunk(t_algo algo, int value)
{
	int i;
	int max;

	i = (algo.current - 1) * algo.chunk_size;
	max = i + algo.chunk_size;
	while (i < max)
	{
		if (algo.sort[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	get_chunk(t_list **a, t_algo *algo)
{
	t_list	*tmp;
	int		t;

	tmp = *a;
	t = 0;
	while (tmp)
	{
		if (is_in_chunk(*algo, tmp->data))
		{
			t = 1;
		}
		tmp = tmp->next;
	}
	if (!t)
	{
		algo->current++;
	}
}

void	find_loop(t_list *tmp, t_algo *algo)
{
	int i;

	i = algo->a_len - 1;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		if (is_in_chunk(*algo, tmp->data))
		{
			algo->h_second = tmp->data;
			algo->second_pos = i;
			break ;
		}
		i--;
		tmp = tmp->prev;
	}
}

int		find_hold(t_list **a, t_algo *algo)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	get_chunk(a, algo);
	while (tmp)
	{
		if (is_in_chunk(*algo, tmp->data))
		{
			algo->h_first = tmp->data;
			algo->first_pos = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	find_loop(tmp, algo);
	return (0);
}
