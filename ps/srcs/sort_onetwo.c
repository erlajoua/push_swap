/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_onetwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:40:08 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/22 20:43:07 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_onetwo(t_list **a)
{
	printf("salut\n");
	if ((*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
			ft_swap(&(*a)->data, &(*a)->next->data);
	}
}
