/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:32:15 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/28 13:32:00 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "libft.h"

void	clean_stacks(t_stacks **stacks, int args)
{
	free((*stacks)->stacka);
	free((*stacks)->stackb);
	if (args != 1)
		free((*stacks)->args);
	free(*stacks);
}

int		arg_error_iter(char *args, char *check, int i, int j)
{
	char	**ins;
	int		matched;

	matched = 0;
	ins = (char**)malloc(sizeof(char*) * 3);
	ins[0] = read_ins(check, i);
	ins[1] = read_ins(args, j);
	if (ft_strequ(ins[0], ins[1]))
		matched = 1;
	free(ins[0]);
	free(ins[1]);
	free(ins);
	return (matched);
}

void	exit_func(t_stacks **stacks, int ex)
{
	clean_stacks(stacks, ex);
	exit(0);
}

void	free_dbl(char ***dbl, int strt)
{
	int i;

	i = 0;
	while (i < strt + 1)
	{
		free(dbl[0][i]);
		i++;
	}
	free(dbl[0]);
}
