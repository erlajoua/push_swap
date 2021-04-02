/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:50:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 14:34:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*lstcpy(t_list **lst)
{
	t_list *cp;
	t_list *tmp;

	cp = NULL;
	tmp = *lst;
	while (tmp)
	{
		push_back(&cp, tmp->data);
		tmp = tmp->next;
	}
	return (cp);
}

void	init_check(t_check *ch)
{
	ch->a_cp = NULL;
	ch->b_cp = NULL;
	ch->i = 3;
	ch->save = 0;
}

int		check_all(t_list **a, t_list **b, int size)
{
	t_check ch;

	init_check(&ch);
	while (ch.i <= 30)
	{
		ch.a_cp = lstcpy(a);
		ch.b_cp = lstcpy(b);
		ch.mysize.size = size;
		ch.mysize.chunksize = ch.i;
		ch.ret = algo(&(ch.a_cp), &(ch.b_cp), &(ch.mysize), HIDE);
		if ((ch.i == 3) || (ch.ret < ch.prev))
		{
			ch.prev = ch.ret;
			ch.save = ch.i;
		}
		lst_clear(&(ch.a_cp));
		lst_clear(&(ch.b_cp));
		ch.i++;
	}
	return (ch.save);
}
