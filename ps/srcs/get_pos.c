/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:18:44 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/01 13:16:07 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		get_pos(t_list **b, int value)
{
	int		size;
	int		*tab;
	int		i;

	size = list_len(b);
	tab = list_to_tab(b);
	i = 0;
	while (i < size - 1)
	{
		if (i == 0)
			if (value < tab[size - 1] && value > tab[i])
			{
				free(tab);
				return (i);
			}
		if (value < tab[i] && value > tab[i + 1])
		{
			free(tab);
			return (i + 1);
		}
		i++;
	}
	free(tab);
	return (-1);
}

int		get_rpos(t_list **a, int value)
{
	int		size;
	int		*tab;
	int		i;

	size = list_len(a);
	tab = list_to_tab(a);
	i = 0;
	while (i < size - 1)
	{
		if (i == 0)
			if (value > tab[size - 1] && value < tab[i])
			{
				free(tab);
				return (i);
			}
		if (value > tab[i] && value < tab[i + 1])
		{
			free(tab);
			return (i + 1);
		}
		i++;
	}
	free(tab);
	return (-1);
}

int		get_bigger_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		bigger;
	int		pos;

	tmp = (*lst)->next;
	i = 1;
	bigger = (*lst)->data;
	pos = 0;
	while (tmp)
	{
		if (tmp->data > bigger)
		{
			bigger = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int		get_lower_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		lower;
	int		pos;

	tmp = (*lst)->next;
	i = 1;
	lower = (*lst)->data;
	pos = 0;
	while (tmp)
	{
		if (tmp->data < lower)
		{
			lower = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
