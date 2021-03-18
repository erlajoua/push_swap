/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:25:22 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 14:14:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_list **a)
{
	int		num[3];

	fill_tab(a, num, 3);
	if ((num[0] > num[1]) && (num[0] < num[2]) && (num[1] < num[2]))
		sa(a);
	else if ((num[0] > num[1]) && (num[1] > num[2]))
	{
		sa(a);
		rra(a);
	}
	else if ((num[0] > num[1]) && (num[0] > num[1]) && (num[1] < num[2]))
		ra(a);
	else if ((num[0] < num[1]) && (num[0] < num[2]) && (num[1] > num[2]))
	{
		sa(a);
		ra(a);
	}
	else if ((num[0] < num[1]) && (num[0] > num[2]) && (num[1] > num[2]))
		rra(a);
}
