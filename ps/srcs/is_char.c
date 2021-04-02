/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:47:01 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/19 09:47:34 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		is_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_arg(char *av)
{
	long n;

	n = long_atoi(av);
	if (n < -2147483648 || n > 2147483647)
		return (0);
	while (*av)
	{
		if (*av != '-' && *av != '+' && !ft_isdigit(*av))
			return (0);
		av++;
	}
	return (1);
}

int		check_duplicate(t_list **a, int data)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->data == data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	long_atoi(char *str)
{
	int		i;
	long	ret;
	int		sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * sign);
}
