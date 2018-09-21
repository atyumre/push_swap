/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_intructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:17:14 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/14 16:19:46 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swaps(t_stacks *stacks, char func)
{
	if (func == '0')
		ft_do_swaps(stacks, "sa");
	else if (func == '1')
		ft_do_swaps(stacks, "sb");
	else if (func == '2')
		ft_do_swaps(stacks, "ss");
}

void	ft_pushs(t_stacks *stacks, char func)
{
	if (func == '3')
		ft_do_swaps(stacks, "pa");
	else if (func == '4')
		ft_do_swaps(stacks, "pb");
}

void	ft_rots(t_stacks *stacks, char func)
{
	if (func == '5')
		ft_do_rot(stacks, "ra");
	else if (func == '6')
		ft_do_rot(stacks, "rb");
	else if (func == '7')
		ft_do_rot(stacks, "rr");
}

void	ft_revrots(t_stacks *stacks, char func)
{
	if (func == '8')
		ft_do_rev_rot(stacks, "rra");
	else if (func == '9')
		ft_do_rev_rot(stacks, "rrb");
	else if (func == 'A')
		ft_do_rev_rot(stacks, "rrr");
}

int		ft_algo_sorted(int *stack, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}
