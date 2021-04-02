/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:33 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 21:16:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int		parse_arg(char *str, t_list **a)
{
	char	**strs;
	int		i;
	int		flag;

	flag = 1;
	i = 0;
	if (is_space(str))
	{
		strs = ft_split(str, ' ');
		while (strs[i])
		{
			if (!check_arg(strs[i]) && !check_duplicate(a, ft_atoi(strs[i])))
				flag = 0;
			push_back(a, ft_atoi(strs[i]));
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	else if (check_arg(str) && check_duplicate(a, ft_atoi(str)))
		push_back(a, ft_atoi(str));
	else
		flag = 0;
	return (flag);
}

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

	i = 1;
	while (i < ac)
	{
		if (!parse_arg(av[i], a))
		{
			write(STDERR_FILENO, "Error\n", 6);
			lst_clear(a);
			return (0);
		}
		i++;
	}
	return (1);
}
