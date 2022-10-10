/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:04:10 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/27 17:04:13 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_args(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (argc > 2)
		args = ft_arg2(argv);
	return (args);
}

char	**ft_arg2(char **argv)
{
	char	**args;
	int		x;
	int		i;

	x = 1;
	i = 0;
	while (argv[x])
		x++;
	args = malloc(sizeof (char *) * x + 1);
	if (args == NULL)
		return (NULL);
	x = 1;
	while (argv[x] != NULL)
	{
		args[i] = argv[x];
		x++;
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	ft_check_size(t_stack *a, t_stack *b)
{
	if (ft_stack_size(a) == 2)
		ft_sa(&a);
	if (ft_stack_size(a) == 3)
		ft_sort3(&a);
	if (ft_stack_size(a) == 4)
		ft_sort4(&a, &b);
	if (ft_stack_size(a) == 5)
		ft_sort5(&a, &b);
	else if (ft_stack_size(a) > 5)
		ft_find_n_and_sort(&a, &b);
}
