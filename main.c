/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:04:41 by rmarquit          #+#    #+#             */
/*   Updated: 2022/03/27 17:04:42 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	ft_first_check(argc, argv);
	ft_check_for_copies(argv);
	args = ft_args(argc, argv);
	ft_check_order(args);
	a = ft_create_stack_a(args);
	ft_set_index(&a);
	if (ft_stack_size(a) < 2)
		exit(1);
	ft_check_size(a, b);
	ft_freestack(&a, free);
	if (argc == 2)
		ft_free_args(args);
	else
		free(args);
	return (0);
}
