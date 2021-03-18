/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:28:21 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/18 11:55:35 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		find_min(int *tab, int len)
{
	int i;
	int min;

	min = 2147483647;
	i = 0;
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int		*list_to_tab(t_list **lst)
{
	int		*tab;
	int		len;
	int		i;
	t_list	*tmp;

	i = 0;
	len = list_len(lst);
	tab = malloc(sizeof(int) * len);
	tmp = *lst;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void	fill_tab(t_list **a, int *tab, int index)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	while (tmp && i < index)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
}
