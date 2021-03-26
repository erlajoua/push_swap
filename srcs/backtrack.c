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

int		check_all(t_list **a, t_list **b, int size)
{
	int i;
	int ret;
	int prev;
	int save;
	t_list *a_cp = NULL;
	t_list *b_cp = NULL;

	i = 3;
	save = 0;
	while (i <= 35)
	{
		a_cp = lstcpy(a);
		b_cp = lstcpy(b);
		//print_list(&a_cp, &b_cp);
		//printf("HIDE : %d\n", HIDE);
		ret = algo(&a_cp, &b_cp, size, i, HIDE);
		//printf("ret = %d   pour chunksize = %d\n", ret, i);
		if (i == 3)
		{
			prev = ret;
			save = i;
		}
		else if (ret < prev)
		{
			prev = ret;
			save = i;
		}
		lst_clear(&a_cp);
		lst_clear(&b_cp);
		i++;
	}
	return (save);
	//printf("best chunksize = %d\n", save);
}
