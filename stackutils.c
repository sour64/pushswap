/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:23:58 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/10 20:24:02 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(long num)
{
	t_stack	*a;

	a = ft_calloc(sizeof (t_stack), 1);
	if (a == NULL)
		return (NULL);
	a->data = num;
	a->next = NULL;
	return (a);
}

t_stack	*slast(t_stack *a)
{
	while (a)
	{
		if (!a->next)
			return (a);
		a = a->next;
	}
	return (a);
}

void	add_b(t_stack **a, t_stack *na)
{
	t_stack	*la;

	if (a)
	{
		if (*a)
		{
			la = slast(*a);
			la->next = na;
		}
		else
			*a = na;
	}
}

t_stack	*ft_create_stack_a(char **args)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	i = 1;
	a = newstack(ft_atoi(args[0]));
	while (args[i])
	{
		if (args[i] == NULL)
			break ;
		tmp = newstack(ft_atoi(args[i]));
		add_b(&a, tmp);
		i++;
	}
	return (a);
}

void	ft_freestack(t_stack **a, void (*del)(void *))
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		(del)(tmp);
	}
	*a = NULL;
}
