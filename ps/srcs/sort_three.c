/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:34:22 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/03 11:34:22 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_list **a)
{
	int		num[3];

	fill_tab(a, num, 3);
	if ((num[0] > num[1]) && (num[0] < num[2]) && (num[1] < num[2]))
		sa(a, SHOW);
	else if ((num[0] > num[1]) && (num[1] > num[2]))
	{
		sa(a, SHOW);
		rra(a, SHOW);
	}
	else if ((num[0] > num[1]) && (num[0] > num[1]) && (num[1] < num[2]))
		ra(a, SHOW);
	else if ((num[0] < num[1]) && (num[0] < num[2]) && (num[1] > num[2]))
	{
		sa(a, SHOW);
		ra(a, SHOW);
	}
	else if ((num[0] < num[1]) && (num[0] > num[2]) && (num[1] > num[2]))
		rra(a, SHOW);
}
