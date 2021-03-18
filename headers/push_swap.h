#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct					s_list
{
	int			data;
	struct		s_list *prev;
	struct		s_list *next;
};
typedef struct s_list	t_list;

int			ft_atoi(char *str);
int			list_len(t_list **lst);
int			*list_to_tab(t_list **lst);
void		push_back(t_list **lst, int data);
void		push_front(t_list **lst, int data);
void		print_list(t_list **a, t_list **b);
void		remove_top(t_list **lst);
void		parsing(int ac, char **av, t_list **a, t_list **b);
void		lst_clear(t_list **lst);
void		pb(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rra(t_list **a);
void		sort_three(t_list **a);
void		sort_five(t_list **a, t_list **b);
void		sort_general(t_list **a, t_list **b);
void		fill_tab(t_list **a, int *tab, int index);
void		ft_swap(int *a, int *b);
t_list		*init_list(int data);

#endif
