/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:36:06 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/29 13:29:23 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "checker.h"

int		ft_duplicates(int size, char **num)
{
	int		*arr;
	int		i;
	int		j;

	arr = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		arr[i] = ft_atoi(num[i]);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != i && arr[j] == arr[i])
			{
				free(arr);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(arr);
	return (0);
}

int		ft_notnum(int size, char **num)
{
	int i;
	int x;

	i = 0;
	while (i < size)
	{
		x = 0;
		if (num[i][0] == '-')
			x++;
		while (num[i][x])
		{
			if (num[i][x] < '0' || num[i][x] > '9')
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int		ft_toobig(int size, char **num)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < size)
	{
		if ((num[i][0] != '-' && ft_atoi(num[i]) < 0) || (num[i][0] == '-' &&
				ft_atoi(num[i]) > 0))
			return (1);
		if ((ft_atoi(num[i]) == -1 && ft_strcmp(num[i], "-1") != 0) ||
				(ft_atoi(num[i]) == 0 && ft_strcmp(num[i], "0") != 0))
			return (1);
		temp = ft_itoa(ft_atoi(num[i]));
		if (ft_strequ(num[i], temp) == 0)
		{
			free(temp);
			return (1);
		}
		free(temp);
		i++;
	}
	return (0);
}

int		ft_error_check(int size, char **num)
{
	char	**temp;
	int		temp_size;

	temp_size = 0;
	if (size == 1)
	{
		temp = ft_strsplit(*num, ' ');
		while (ft_strequ(temp[temp_size], 0) != 1)
			temp_size++;
		if (ft_notnum(temp_size, temp) || ft_toobig(temp_size, temp) ||
			ft_duplicates(temp_size, temp))
		{
			free_dbl(&temp, temp_size);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		free_dbl(&temp, temp_size);
	}
	else if (ft_notnum(size, num) || ft_toobig(size, num) ||
			ft_duplicates(size, num))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

int		ft_arg_error(char *args, int num_args)
{
	char	*check;
	int		i;
	int		j;
	int		matched;

	check = "sa+sb+ss+pa+pb+ra+rb+rr+rra+rrb+rrr";
	j = 0;
	while (j < num_args)
	{
		matched = 0;
		i = 0;
		while (i < 11)
		{
			if (arg_error_iter(args, check, i, j))
				matched = 1;
			i++;
		}
		if (matched == 0)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		j++;
	}
	return (1);
}
