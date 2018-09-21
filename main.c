/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:16:13 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/28 13:44:33 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	stacks->stacka = (int*)malloc(sizeof(int) * argc);
	stacks->stackb = (int*)malloc(sizeof(int) * argc);
	stacks->stacka_size = argc - 1;
	stacks->stackb_size = 0;
	if (argc != 1)
	{
		if (ft_error_check(argc - 1, &argv[1]) == 0)
			exit_func(&stacks, 1);
		ft_stackinit(&(stacks->stacka), &argv[1], argc - 1,
				&(stacks->stacka_size));
		stacks->args = ft_arguments(stacks);
		if (ft_arg_error(stacks->args, stacks->num_args) == 0)
			exit_func(&stacks, 0);
		ft_sort(stacks);
		ft_sorted(stacks->stacka, stacks->stacka_size, stacks->stackb_size);
	}
	clean_stacks(&stacks, argc);
	return (0);
}
