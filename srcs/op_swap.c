/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:00:31 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 15:40:12 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_list **a)
{
	t_list	*curr;
	t_list	*next;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	curr = *a;
	next = (*a)->next;
	ft_swap(&(curr->data), &(next->data));
	printf("sa\n");
}

void	sb(t_list **b)
{
	t_list	*curr;
	t_list	*next;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	curr = *b;
	next = (*b)->next;
	ft_swap(&(curr->data), &(next->data));
	printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}
