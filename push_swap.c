/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:39:45 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/28 13:26:59 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			sorted;

	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	if (argc != 1)
	{
		if (ft_error_check(argc - 1, &argv[1]) == 0)
		{
			free(stacks);
			return (0);
		}
		stacks->stacka = (int*)malloc(sizeof(int) * (argc - 1));
		stacks->stackb = (int*)malloc(sizeof(int) * (argc - 1));
		stacks->stacka_size = argc - 1;
		stacks->stackb_size = 0;
		ft_stackinit(&(stacks->stacka), &argv[1], argc - 1,
				&(stacks->stacka_size));
		sorted = ft_algo_sorted(stacks->stacka, stacks->stacka_size);
		free(stacks->stacka);
		free(stacks->stackb);
		if (sorted == 0)
			swap_algo(stacks, &argv[1], argc - 1);
	}
	free(stacks);
	return (0);
}
