/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:03:16 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/27 17:03:18 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_index(t_stack **b)
{
	t_stack	*tmp;
	int		n;

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

t_stack	*ft_pre_last(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*pre;

	tmp = a;
	pre = a;
	while (tmp->next)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	return (pre);
}

int	ft_stack_size(t_stack *a)
{
	size_t	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_is_sorted(t_stack *a)
{
	t_stack	*head;

	head = a;
	while (head && (head->next != NULL))
	{
		if (head->data > head->next->data)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_set_index(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *a;
	while (current)
	{
		tmp = *a;
		current->i = 0;
		while (tmp)
		{
			if (current->data > tmp->data)
				current->i = current->i + 1;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
