/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:50:53 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/16 14:28:23 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
	{
		printf("usage %s [integer1] [integer2]\n", av[0]);
		return (0);
	}
	parsing(ac, av, &a, &b);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
