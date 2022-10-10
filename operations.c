/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:02:29 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/27 17:02:32 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (ft_stack_size(*a) > 0)
	{
		temp1 = *a;
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		temp2->next = temp1;
		*a = temp2;
		write (1, "sa\n", 3);
	}
}

void	ft_sb(t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (ft_stack_size(*b) > 0)
	{
		temp1 = *b;
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		temp2->next = temp1;
		*b = temp2;
		write (1, "sb\n", 3);
	}
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = NULL;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = NULL;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	ft_rotate_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	slast(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
