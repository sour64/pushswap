/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:27:36 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/22 17:27:39 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	slast(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr_a(t_stack **a)
{
	t_stack	*tmp;

	if (ft_stack_size(*a) > 1)
	{
		tmp = slast(*a);
		ft_pre_last(*a)->next = NULL;
		tmp->next = *a;
		*a = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rr_b(t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*b) > 1)
	{
		tmp = slast(*b);
		ft_pre_last(*b)->next = NULL;
		tmp->next = *b;
		*b = tmp;
		write(1, "rrb\n", 4);
	}
}

int	ft_findmax(t_stack **b)
{
	int		n;
	t_stack	*tmp;

	n = -1;
	tmp = *b;
	while (tmp)
	{
		if (tmp->i > n)
			n = tmp->i;
		tmp = tmp->next;
	}
	return (n);
}
