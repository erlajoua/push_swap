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

struct					s_algo
{
	int *sort;
	int chunk_nb;
	int chunk_size;
	int	current;
	int h_first;
	int h_second;
	int first_pos;
	int second_pos;
	int a_len;
	int b_len;
	int	ra;
	int rb;
	int rra;
	int rrb;
	int rr;
	int rrr;
};
typedef struct s_algo	t_algo;


int			ft_atoi(char *str);
int			list_len(t_list **lst);
int			find_index_min(int *tab, int len);
int			parsing(int ac, char **av, t_list **a, t_list **b);
int			is_smaller(t_list **lst, int value);
int			is_bigger(t_list **lst, int value);
int			is_space(char *str);
int			is_num(char c);
int			get_pos(t_list **b, int value);
int			*list_to_tab(t_list **lst);
int			*sort_list(t_list **a, int size);
int			get_bigger_pos(t_list **lst);
int			get_movs(t_algo *algo);
int			is_in_chunk(t_algo algo, int value);
int			find_hold(t_list **a, t_algo *algo);
void		push_back(t_list **lst, int data);
void		push_front(t_list **lst, int data);
void		print_list(t_list **a, t_list **b);
void		remove_top(t_list **lst);
void		lst_clear(t_list **lst);
void		pb(t_list **a, t_list **b, int option);
void		pa(t_list **a, t_list **b, int option);
void		sa(t_list **a, int option);
void		sb(t_list **b, int option);
void		ss(t_list **a, t_list **b, int option);
void		ra(t_list **a, int option);
void		rb(t_list **b, int option);
void		rr(t_list **a, t_list **b, int option);
void		rra(t_list **a, int option);
void		rrb(t_list **b, int option);
void		rrr(t_list **a, t_list **b, int option);
void		sort_three(t_list **a);
void		sort_five(t_list **a, t_list **b, int ac);
void		sort_general(t_list **a, t_list **b);
void		sort_onetwo(t_list **a);
void		fill_tab(t_list **a, int *tab, int index);
void		ft_swap(int *a, int *b);
void		ft_putstr_fd(char *str, int fd);
void		get_values(t_list **b, t_algo *algo);
void		algo(t_list **a, t_list **b, int size);
void		get_chunk(t_list **a, t_algo *algo);
void		swap_to_a(t_list **a, t_list **b);
void		swap_to_b(t_list **a, t_list **b);
void		ft_rooftop(t_list **a, t_algo *algo);
char		**ft_split(char const *s, char c);
t_list		*init_list(int data);

#endif
