/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:33 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/01 13:07:22 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		get_list_a(t_list **a, int ac, char **av)
{
	int		i;
	int		data;

	i = 1;
	while (i < ac)
	{
		data = (int)long_atoi(av[i]);
		if (check_arg(av[i]) && check_duplicate(a, data))
			push_back(a, data);
		else
		{
			write(STDERR_FILENO, "Error\n", 6);
			lst_clear(a);
			return (0);
		}
		i++;
	}
	return (1);
}
