/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort35.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:11:43 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/22 18:11:46 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **a)
{
	while (a && (ft_is_sorted(*a)))
	{
		if ((*a)->i > (*a)->next->i)
			ft_sa(a);
		else if ((*a)->next->i > (*a)->next->next->i)
			ft_rr_a(a);
	}
}

void	ft_sort4(t_stack **a, t_stack **b)
{
	int	l;

	l = ft_find_min(*a);
	if (l == 1)
		ft_sa(a);
	if (l == 2)
	{
		ft_rotate_a(a);
		ft_rotate_a(a);
	}
	else if (l == 3)
		ft_rr_a(a);
	if (ft_is_sorted(*a) == 0)
		return ;
	ft_push_b(a, b);
	ft_sort3(a);
	ft_push_a(a, b);
}

int	ft_min_index(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	i = 0;
	tmp = a;
	min = tmp->i;
	while (tmp)
	{
		if (tmp->i < min)
			min = tmp->i;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

int	ft_find_min(t_stack *a)
{
	int	l;

	l = 0;
	while (a->next)
	{
		if (a->i == ft_min_index(a))
			break ;
		a = a->next;
		l++;
	}
	return (l);
}

void	ft_sort5(t_stack **a, t_stack **b)
{
	int	l;

	l = ft_find_min(*a);
	if (l == 1)
		ft_sa(a);
	if (l == 2)
	{
		ft_rotate_a(a);
		ft_rotate_a(a);
	}
	if (l == 3)
	{
		ft_rr_a(a);
		ft_rr_a(a);
	}
	if (l == 4)
		ft_rr_a(a);
	ft_push_b(a, b);
	ft_sort4(a, b);
	ft_push_a(a, b);
}
