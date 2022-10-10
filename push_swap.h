/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:16:42 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/27 17:16:45 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				i;
	long			data;
	struct s_stack	*next;
}					t_stack;

int		ft_first_check(int argc, char **argv);
int		ft_space(char *str);
void	ft_check_for_numbers(char *str);
void	ft_check_str(char *str);
void	ft_error(void);
long	ft_atoi( char *str);
int		ft_check_for_copies(char **argv);
int		ft_check_order(char **args);
int		ft_wordcount(char const *s, char c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t n, size_t size);
void	ft_separation(int argc, char **argv);
t_stack	*newstack(long num);
t_stack	*slast(t_stack *a);
t_stack	*ft_pre_last(t_stack *a);
int		ft_stack_size(t_stack *a);
int		ft_is_sorted(t_stack *a);
void	ft_set_index(t_stack **a);
void	add_b(t_stack **a, t_stack *na);
t_stack	*ft_create_stack_a(char **args);
char	**ft_args(int argc, char **argv);
char	**ft_arg2(char **argv);
void	ft_freestack(t_stack **a, void (*del)(void *));
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_rotate_a(t_stack	**a);
void	ft_rotate_b(t_stack **b);
void	ft_rr_a(t_stack **a);
void	ft_rr_b(t_stack **b);
void	ft_butterfly(t_stack **a, t_stack **b, int n);
void	ft_find_n_and_sort(t_stack **a, t_stack **b);
int		ft_max_index(t_stack **b);
int		ft_min_index(t_stack *b);
int		ft_find_min(t_stack *a);
void	ft_pmax_b(t_stack **a, t_stack **b);
int		ft_distance(t_stack *b);
void	ft_check_size(t_stack *a, t_stack *b);
void	ft_sort3(t_stack **a);
void	ft_sort4(t_stack **a, t_stack **b);
void	ft_sort5(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_final_push(t_stack **a, t_stack **b);
void	*ft_free_args(char **s);
int		main(int argc, char **argv);

#endif
