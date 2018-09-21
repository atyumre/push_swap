/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useintructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:39:02 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/06 15:55:26 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	ft_do_swaps(t_stacks *stacks, char *ins)
{
	if (ft_strcmp(ins, "sa") == 0)
		ft_swap(stacks->stacka, stacks->stacka_size);
	else if (ft_strcmp(ins, "sb") == 0)
		ft_swap(stacks->stackb, stacks->stackb_size);
	else if (ft_strcmp(ins, "ss") == 0)
	{
		ft_swap(stacks->stacka, stacks->stacka_size);
		ft_swap(stacks->stackb, stacks->stackb_size);
	}
}

void	ft_do_push(t_stacks *stacks, char *ins)
{
	if (ft_strcmp(ins, "pa") == 0)
		ft_push(stacks->stacka, stacks->stackb, &(stacks->stacka_size),
				&(stacks->stackb_size));
	else if (ft_strcmp(ins, "pb") == 0)
		ft_push(stacks->stackb, stacks->stacka, &(stacks->stackb_size),
				&(stacks->stacka_size));
}

void	ft_do_rot(t_stacks *stacks, char *ins)
{
	if (ft_strcmp(ins, "ra") == 0)
		ft_rotate(stacks->stacka, stacks->stacka_size);
	else if (ft_strcmp(ins, "rb") == 0)
		ft_rotate(stacks->stackb, stacks->stackb_size);
	else if (ft_strcmp(ins, "rr") == 0)
	{
		ft_rotate(stacks->stacka, stacks->stacka_size);
		ft_rotate(stacks->stackb, stacks->stackb_size);
	}
}

void	ft_do_rev_rot(t_stacks *stacks, char *ins)
{
	if (ft_strcmp(ins, "rra") == 0)
		ft_rev_rot(stacks->stacka, stacks->stacka_size);
	else if (ft_strcmp(ins, "rrb") == 0)
		ft_rev_rot(stacks->stackb, stacks->stackb_size);
	else if (ft_strcmp(ins, "rrr") == 0)
	{
		ft_rev_rot(stacks->stacka, stacks->stacka_size);
		ft_rev_rot(stacks->stackb, stacks->stackb_size);
	}
}
