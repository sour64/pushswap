/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:40:48 by rmarquit          #+#    #+#             */
/*   Updated: 2021/10/18 19:40:49 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	long	i;
	int		x;
	int		m;

	x = 0;
	i = 0;
	m = 1;
	if (s[0] == '-')
	{
		m = -1;
		x++;
	}
	if (s[0] == '+')
		x++;
	while (s[x])
	{
		i = i * 10;
		i += s[x++] - '0';
	}
	if (i * m > INT_MAX || i * m < INT_MIN)
	{
		write (1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (i * m);
}

int	ft_check_for_copies(char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = i + 1;
		while (argv[x])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[x]))
			{
				write(1, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		i++;
	}
	return (0);
}

void	ft_pmax_b(t_stack **a, t_stack **b)
{
	if ((*b)->i == ft_max_index(b))
		ft_push_a(a, b);
	if ((*b)->next->i == ft_max_index(b))
	{
		ft_sb(b);
		ft_push_a(a, b);
	}
}

int	ft_distance(t_stack *b)
{
	int	l;

	l = 0;
	while (b->next)
	{
		if (b->i == ft_max_index(&b))
			break ;
		b = b->next;
		l++;
	}
	return (l);
}

int	ft_check_order(char **args)
{
	int	i;
	int	x;

	i = 0;
	while (args[i])
	{
		x = i;
		while (args[x])
		{
			if (ft_atoi(args[i]) > ft_atoi(args[x]) && args[i] != NULL)
				return (0);
				x++;
		}
		i++;
	}
	exit(EXIT_FAILURE);
}
