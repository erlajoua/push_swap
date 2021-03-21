#include "../headers/push_swap.h"

int		*sort_list(t_list **lst, int size)
{
	int *tab;
	int i;

	tab = list_to_tab(lst);
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return (tab);
}

int		is_in_chunk(t_algo algo, int value)
{
	int i;
	int max;

	i = (algo.current - 1) * algo.chunk_size; // -1 ?
	max = i + algo.chunk_size;
	while (i < max)
	{
		if (algo.sort[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	get_chunk(t_list **a, t_algo *algo)
{
	t_list	*tmp;
	int		t;

	tmp = *a;
	t = 0;
	while (tmp->next)
	{
		if (is_in_chunk(*algo, tmp->data))
			t = 1;
		tmp = tmp->next;
	}
	if (!t)
		algo->current++;
}

int		find_hold(t_list **a, t_algo *algo)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	get_chunk(a, algo);
	while (tmp->next)
	{
		if (is_in_chunk(*algo, tmp->data))
		{
			algo->h_first = tmp->data;
			algo->first_pos = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	i = algo->a_len;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		if (is_in_chunk(*algo, tmp->data))
		{
			algo->h_second = tmp->data;
			algo->second_pos = i;
			break ;
		}
		i--;
		tmp = tmp->prev;
	}
	return (0);
}

void	print_sort(int *sort, int size) // a supp
{
	int i;

	i = 0;
	printf("\nSORT:\n\n");
	while (i < size)
	{
		printf("%d  ", sort[i]);
		i++;
	}
	printf("\n");
}

void	init_algo(t_algo *algo, t_list **a, int size)
{
	algo->chunk_size = size;
	algo->sort = sort_list(a, size);
	//print_sort(algo->sort, size); // a enlever
	if (algo->chunk_size / 2 > 20)
		while (algo->chunk_size / 2 > 20)
			algo->chunk_size /= 2;
	else
		algo->chunk_size /= 2;
	algo->chunk_nb = size / algo->chunk_size;
	algo->current = 1;
	//printf("chunk_size = %d\n", algo->chunk_size); // a enlever
}

int		get_movs(t_algo *algo)
{
	int middle;
	int first_movs;
	int second_movs;

	middle = algo->a_len / 2;
	first_movs = algo->first_pos;
	if (algo->first_pos > middle)
		first_movs = algo->a_len - algo->first_pos * -1;
	second_movs = algo->a_len - algo->second_pos * -1;
	if (algo->second_pos < middle)
		second_movs = algo->second_pos;
	if (first_movs < second_movs)
		return (first_movs);
	return (second_movs);
}

void	ft_rooftop(t_list **a, t_algo *algo)
{
	int top_movs;

	top_movs = get_movs(algo);
	if (top_movs < 0)
		while (top_movs++ < 0)
			rra(a, 1);
	else
		while (top_movs-- > 0)
			ra(a, 1);
}

int		get_pos(t_list **b, int value)
{
	t_list	*tmp;
	int		size;
	int		*tab;
	int		i;

	tmp = *b;
	size = list_len(b);
	tab = list_to_tab(b);
	i = 0;
	while (i < size - 1)
	{
		if (i == 0)
		//{
			if (value < tab[size - 1] && value > tab[i])
				return (i);
			//if (value < tab[i] && value > tab[i + 1])
		//}
		if (value < tab[i] && value > tab[i + 1])
			return (i + 1);
		i++;
	}
	free(tab);
	printf("get_pos return (-1)\n");
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

int		get_smaller_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		smaller;
	int		pos;
 
	tmp = (*lst)->next;
	i = 1;
	smaller = (*lst)->data;
	pos = 0;
	while (tmp)
	{
		if (tmp->data < smaller)
		{
			smaller = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	swap_to_b(t_list **a, t_list **b)
{
	int pos;
	int b_len;
	int	movs;

	if (*b && (*b)->next != NULL)//if (!is_smaller(b, (*a)->data) && (*a)->next != NULL)
	{
		if ((pos = get_pos(b, (*a)->data)) == -1)//get_smaller_pos(b);
		{
			if (is_smaller(b, (*a)->data) || is_bigger(b, (*a)->data))
				pos = get_bigger_pos(b);
			//else
				//pos = get_smaller_pos(b);
		}
		//printf("sp = %d\n", pos);
		b_len = list_len(b);
		movs = pos;
		if (pos > b_len / 2)
		{
			//printf("passage\n");
			movs = b_len - pos; // +1 ?
		}
		//printf("movs = %d\n", movs);
		while (movs-- > 0)
		{
			if (pos <= b_len / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
	pb(a, b, 1);
}

void	swap_to_a(t_list **a, t_list **b)
{
	int bp;
	int b_len;
	int movs;

	bp = get_bigger_pos(b);
	//printf("bp = %d\n", bp);
	b_len = list_len(b);
	movs = bp;
	if (bp > b_len / 2)
		movs = b_len - bp;
	while (movs-- > 0)
	{
		if (bp <= b_len / 2)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	//print_list(a, b);
	while (*b != NULL)
		pa(a, b, 1);
	print_list(a, b);
}

void	algo(t_list **a, t_list **b, int size)
{
	t_algo	algo;

	printf("\n\n");
	int i = 0;
	init_algo(&algo, a, size);
	if (size > 5)
	{
		while (i < 10)//(*a != NULL)
		{
			algo.a_len = list_len(a);
			find_hold(a, &algo);
			printf("first = %d pos %d      second = %d pos %d\n", algo.h_first, algo.first_pos, algo.h_second, algo.second_pos);
			ft_rooftop(a, &algo);
			print_list(a, b);
			swap_to_b(a, b);
			print_list(a, b);
			i++;//*a = NULL;
		}
		swap_to_a(a, b);
	}
}