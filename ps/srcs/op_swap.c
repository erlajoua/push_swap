/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:00:31 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 07:52:51 by user42           ###   ########.fr       */
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

void	sa(t_list **a, int option)
{
	t_list	*curr;
	t_list	*next;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	curr = *a;
	next = (*a)->next;
	ft_swap(&(curr->data), &(next->data));
	if (option == SHOW)
		printf("sa\n");
}

void	sb(t_list **b, int option)
{
	t_list	*curr;
	t_list	*next;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	curr = *b;
	next = (*b)->next;
	ft_swap(&(curr->data), &(next->data));
	if (option == SHOW)
		printf("sb\n");
}

void	ss(t_list **a, t_list **b, int option)
{
	sa(a, HIDE);
	sb(b, HIDE);
	if (option == SHOW)
		printf("ss\n");
}
