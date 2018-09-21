/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyumre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:26:50 by atyumre           #+#    #+#             */
/*   Updated: 2018/08/28 13:44:31 by atyumre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef	struct	s_stacks
{
	int			*stacka;
	int			*stackb;
	int			stacka_size;
	int			stackb_size;
	char		*args;
	int			num_args;
}				t_stacks;

void			ft_stackinit(int **stacka, char **numm, int size,
		int *stacka_size);
char			*ft_arguments(t_stacks *stacks);
void			ft_sort(t_stacks *stacks);
char			*read_ins(char *args, int i);
void			ft_sorted(int *stack, int size, int b_size);
int				ft_duplicate(int size, char **num);
int				ft_notnum(int size, char **num);
int				ft_toobig(int size, char **num);
int				ft_error_check(int size, char **num);
void			ft_swap(int *stack, int size);
void			ft_push(int *stacko, int *stackt, int *sizeo, int *sizet);
void			ft_rotate(int *stack, int size);
void			ft_rev_rot(int *stack, int size);
void			ft_do_swaps(t_stacks *stacks, char *ins);
void			ft_do_push(t_stacks *stacks, char *ins);
void			ft_do_rot(t_stacks *stacks, char *ins);
void			ft_do_rev_rot(t_stacks *stacks, char *ins);
void			swap_algo(t_stacks *stacks, char **nums, int size);
void			ft_add_instructs(t_stacks *stacks, char *funcs);
void			ft_push_instructs(char *funcs);
void			ft_push_instructst(char funcs);
void			ft_brute(char **funcs, int size);
void			ft_swaps(t_stacks *stacks, char func);
void			ft_pushs(t_stacks *stacks, char func);
void			ft_rots(t_stacks *stacks, char func);
void			ft_revrots(t_stacks *stacks, char func);
int				ft_algo_sorted(int *stack, int size);
int				ft_arg_error(char *args, int num_args);
void			clean_stacks(t_stacks **stacks, int args);
int				arg_error_iter(char *args, char *check, int i, int j);
void			exit_func(t_stacks **stacks, int ex);
void			free_dbl(char ***dbl, int strt);

#endif
