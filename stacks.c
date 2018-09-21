/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:58:10 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/28 13:12:11 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

void	ft_stackinit(int **stacka, char **num, int size, int *stacka_size)
{
	int		i;
	char	**temp;

	i = 0;
	if (size == 1)
	{
		temp = ft_strsplit(*num, ' ');
		free(*stacka);
		while (ft_strequ(temp[i], 0) == 0)
			i++;
		*stacka_size = i;
		*stacka = (int*)malloc(sizeof(int) * i);
		i = -1;
		while (++i < *stacka_size)
			(*stacka)[i] = ft_atoi(temp[i]);
		free_dbl(&temp, *stacka_size);
	}
	else
		while (i < size)
		{
			(*stacka)[i] = ft_atoi(num[i]);
			i++;
		}
}

char	*ft_arguments(t_stacks *stacks)
{
	char *line;
	char *instructs;

	line = NULL;
	instructs = ft_strnew(1);
	stacks->num_args = 0;
	while (get_next_line(0, &line) > 0)
	{
		instructs = ft_strjoin_memt(&instructs, &line);
		instructs = ft_strjoin_memo(&instructs, "+");
		(stacks->num_args)++;
	}
	return (instructs);
}

void	ft_sort(t_stacks *stacks)
{
	int		i;
	char	*ins;

	i = 0;
	while (i < stacks->num_args)
	{
		ins = read_ins(stacks->args, i);
		ft_do_swaps(stacks, ins);
		ft_do_push(stacks, ins);
		ft_do_rot(stacks, ins);
		ft_do_rev_rot(stacks, ins);
		free(ins);
		i++;
	}
}

char	*read_ins(char *args, int i)
{
	char	*ins;
	int		x;
	int		y;
	int		space;

	x = 0;
	space = 0;
	while (space < i)
	{
		if (args[x] == '+')
			space++;
		x++;
	}
	y = x;
	while (args[x] != '+' && args[x])
		x++;
	ins = ft_strsub(args, y, x - y);
	return (ins);
}

void	ft_sorted(int *stack, int size, int b_size)
{
	int i;

	i = 1;
	if (b_size != 0)
	{
		ft_putendl("KO");
		exit(0);
	}
	while (i < size)
	{
		if (stack[i] < stack[i - 1])
		{
			ft_putendl("KO");
			exit(0);
		}
		i++;
	}
	ft_putendl("OK");
}
