/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:50:55 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/26 13:53:26 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int   is_sorted(t_list **a)
{
  t_list  *tmp;

  tmp = *a;
  while (tmp->next)
  {
    if (tmp->data > tmp->next->data)
      return (0);
    tmp = tmp->next;
  }
  return (1);
}

int		check_str(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || is_num(str[i]))
		i++;
	while (str[i])
	{
		if (!(is_num(str[i])))
			return (0);
		i++;
	}
	return (1);
}

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
			if (!(check_str(strs[i])))
				flag = 0;
			push_back(a, ft_atoi(strs[i]));
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	else if (check_str(str))
		push_back(a, ft_atoi(str));
	else
		flag = 0;
	return (flag);
}

int		parsing_error(void)
{
	ft_putstr_fd("parsing error\n", STDERR_FILENO);
	return (0);
}

int		parsing(int ac, char **av, t_list **a, t_list **b)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!(parse_arg(av[i], a)))
			return (parsing_error());
		i++;
	}
  if (is_sorted(a))
    return (1);
	if (ac - 1 <= 2)
		sort_onetwo(a);
	else if (ac - 1 == 3)
		sort_three(a);
	else if (ac - 1 <= 5)
		sort_five(a, b, ac);
	else
		algo(a, b, ac - 1, check_all(a, b, ac - 1), SHOW);
	return (1);
}
