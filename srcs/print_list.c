/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:51:31 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/08 11:18:27 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_list(t_list **a, t_list **b)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *a;
	lst_b = *b;
	printf("[a] [b]\n-----\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			printf("%d     ", lst_a->data);
			lst_a = lst_a->next;
		}
		else
			printf("     ");
		if (lst_b)
		{
			printf("%d\n", lst_b->data);
			lst_b = lst_b->next;
		}
		else
			printf(" \n");
	}
}
