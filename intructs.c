/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intructs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:25:14 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/06 15:55:01 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *stack, int size)
{
	int temp;

	if (size >= 2)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

void	ft_push(int *stacko, int *stackt, int *sizeo, int *sizet)
{
	int i;

	i = *sizeo > 0 ? *sizeo - 1 : 0;
	if (*sizet >= 1)
	{
		while (i >= 0)
		{
			stacko[i + 1] = stacko[i];
			i--;
		}
		stacko[0] = stackt[0];
		i = 0;
		while (i < *sizet - 1)
		{
			stackt[i] = stackt[i + 1];
			i++;
		}
		(*sizeo)++;
		(*sizet)--;
	}
}

void	ft_rotate(int *stack, int size)
{
	int temp;
	int i;

	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}

void	ft_rev_rot(int *stack, int size)
{
	int temp;
	int i;

	temp = stack[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = temp;
}
