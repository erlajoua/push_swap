#include "../headers/checker.h"

/*
void	get_instructions() // a faire

void    put_instructions(t_list **a, t_list **b)
{
	// get_instructions on lis l'entree standart avc GNL, recup les instructions et parsing des erreurs
	// ensiute on applique une par une
}

int     is_sort(t_list **a)
{
	// a faire
}

int     is_empty(t_list **b)
{
	// a faire
}
*/

int     main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	
	get_list_a(&a, ac, av);
	print_list(&a, &b); // a enlever
	put_instructions(&a, &b);
	if (is_sort(&a) && is_empty(&b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}