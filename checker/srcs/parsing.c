#include "../headers/checker.h"

long    long_atoi(char *str)
{
    int     i;
	long    ret;
	int     sign;

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

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int     check_arg(char *av)
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

int     check_duplicate(t_list **a, int data)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp)
    {
        if (tmp->data == data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    get_list_a(t_list **a, int ac, char **av)
{
    int     i;
    int     data;

    i = 1;
    while (i < ac)
    {
        data = ft_atoi(av[i]);
        if (check_arg(av[i]) && check_duplicate(a, data))
            push_back(a, data);
        else
        {
            write(1, "Error\n", 6);
            exit (0);
        }
        i++;
    }
}
