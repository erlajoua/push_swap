#include "../headers/checker.h"
#include "../headers/get_next_line.h"

void    put_instructions(t_list **a, t_list **b)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			sa(a, 1);
		else if (ft_strcmp(line, "sb") == 0)
			sb(b, 1);
		else if (ft_strcmp(line, "ss") == 0)
			ss(a, b, 1);
		else if (ft_strcmp(line, "pa") == 0)
			pa(a, b, 1);
		else if (ft_strcmp(line, "pb") == 0)
			pb(a, b, 1);
		else if (ft_strcmp(line, "ra") == 0)
			ra(a, 1);
		else if (ft_strcmp(line, "rb") == 0)
			rb(b, 1);
		else if (ft_strcmp(line, "rr") == 0)
			rr(a, b, 1);
		else if (ft_strcmp(line, "rra") == 0)
			rra(a, 1);
		else if (ft_strcmp(line, "rrb") == 0)
			rrb(b, 1);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(a, b, 1);
		else
			{
				write(1, "Error\n", 6);
				exit (0);
			}
		free(line);
	}
	free(line);
}


int     is_sort(t_list **a)
{
	t_list *tmp;
	
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;		
	}
	return (1);
}

int     main(int ac, char **av)
{
	t_list *a;
	t_list *b;

	b = NULL;
	get_list_a(&a, ac, av);
	print_list(&a, &b);
	printf("\n\n");
	put_instructions(&a, &b);
	printf("\n\n");
	if (is_sort(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	printf("\n\n");
	print_list(&a, &b);
	return (0);
}