/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:28:22 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/23 13:25:19 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "checker.h"

void	swap_algo(t_stacks *stacks, char **nums, int size)
{
	char	*funcs;
	int		i;
	int		sorted;

	funcs = ft_strnew(1);
	i = 0;
	sorted = 0;
	funcs[i] = '0';
	while (sorted != 1)
	{
		stacks->stacka = (int*)malloc(sizeof(int) * size);
		stacks->stackb = (int*)malloc(sizeof(int) * size);
		stacks->stacka_size = size;
		stacks->stackb_size = 0;
		ft_stackinit(&(stacks->stacka), nums, size, &(stacks->stacka_size));
		ft_add_instructs(stacks, funcs);
		if (ft_algo_sorted(stacks->stacka, stacks->stacka_size) == 0)
			ft_brute(&funcs, ft_strlen(funcs) - 1);
		else
			sorted = 1;
		free(stacks->stacka);
		free(stacks->stackb);
	}
	ft_push_instructs(funcs);
	free(funcs);
}

void	ft_add_instructs(t_stacks *stacks, char *funcs)
{
	int i;

	i = 0;
	while (funcs[i])
	{
		if (funcs[i] >= '0' && funcs[i] <= '2')
			ft_swaps(stacks, funcs[i]);
		else if (funcs[i] >= '3' && funcs[i] <= '4')
			ft_pushs(stacks, funcs[i]);
		else if (funcs[i] >= '5' && funcs[i] <= '7')
			ft_rots(stacks, funcs[i]);
		else if (funcs[i] == '8' || funcs[i] == '9' || funcs[i] == 'A')
			ft_revrots(stacks, funcs[i]);
		i++;
	}
}

void	ft_push_instrucst(char funcs)
{
	if (funcs == '6')
		ft_putendl("rb");
	else if (funcs == '7')
		ft_putendl("rr");
	else if (funcs == '8')
		ft_putendl("rra");
	else if (funcs == '9')
		ft_putendl("rrb");
	else if (funcs == 'A')
		ft_putendl("rrr");
}

void	ft_push_instructs(char *funcs)
{
	int i;

	i = 0;
	while (funcs[i])
	{
		if (funcs[i] == '0')
			ft_putendl("sa");
		else if (funcs[i] == '1')
			ft_putendl("sb");
		else if (funcs[i] == '2')
			ft_putendl("ss");
		else if (funcs[i] == '3')
			ft_putendl("pa");
		else if (funcs[i] == '4')
			ft_putendl("pb");
		else if (funcs[i] == '5')
			ft_putendl("ra");
		else
			ft_push_instrucst(funcs[i]);
		i++;
	}
}

void	ft_brute(char **funcs, int size)
{
	int i;

	i = size;
	if ((*funcs)[i] == '9')
		(*funcs)[i] = 'A';
	else if ((*funcs)[i] == 'A' && i != 0)
	{
		ft_brute(funcs, size - 1);
		(*funcs)[i] = '0';
	}
	else if ((*funcs)[i] == 'A' && i == 0)
	{
		*funcs = ft_strjoin_memo(funcs, "0");
		while ((*funcs)[i])
		{
			(*funcs)[i] = '0';
			i++;
		}
	}
	else
		(*funcs)[i]++;
}
