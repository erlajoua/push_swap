/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:05:02 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 11:56:12 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		list_len(t_list **lst)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		is_smaller(t_list **lst, int value)
{
	t_list *tmp;

	if (*lst == NULL)
		return (1);
	tmp = *lst;
	while (tmp)
	{
		if (tmp->data < value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_bigger(t_list **lst, int value)
{
	t_list *tmp;

	if (*lst == NULL)
		return (1);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->data > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
