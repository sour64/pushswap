/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:44:03 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/22 16:44:06 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_n_and_sort(t_stack **a, t_stack **b)
{
	int	n;

	n = 0;
	if (ft_stack_size(*a) + 1 <= 31)
		n = 1;
	else if (ft_stack_size(*a) < 101)
		n = 14;
	else if (ft_stack_size(*a) + 1 >= 102)
		n = 31;
	ft_butterfly(a, b, n);
}

void	ft_butterfly(t_stack **a, t_stack **b, int n)
{
	int	counter;

	counter = 0;
	while (*a)
	{
		if ((*a)->i <= counter)
		{
			ft_push_b(a, b);
			if (ft_stack_size(*b) > 1)
				ft_rotate_b(b);
			counter++;
		}
		else if ((*a)->i <= counter + n)
		{
			ft_push_b(a, b);
			counter++;
		}
		else if ((*a)->i > counter + n)
			ft_rotate_a(a);
	}
	ft_push_b(a, b);
	ft_sort(a, b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*b) > 2)
	{
		ft_pmax_b(a, b);
		if (ft_distance(*b) >= ft_stack_size(*b) / 2 && ft_stack_size(*b) > 1)
		{
			if (ft_stack_size(*b) > 2)
			{
				while ((*b)->i != ft_max_index(b))
					ft_rr_b(b);
			}
		}
		else if (ft_distance(*b) < ft_stack_size(*b) / 2)
		{
			while ((*b)->i != ft_max_index(b))
				ft_rotate_b(b);
		}
	}
	ft_final_push(a, b);
}

void	ft_final_push(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if ((*b)->i == ft_max_index(b))
			ft_push_a(a, b);
		else
			ft_rotate_b(b);
	}
}

void	*ft_free_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
