/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:37:24 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:40:52 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../push_swap.h"

int	initialize(t_data *data);
int	check_dup(int n, t_list *stack);
int	integers(char *str);
int	initialize(t_data *data);
void	ft_parcing(char **argv, t_data *data);

int	get_index(int value, int *numbers, int size);
void	sort_tab(int size, int *number_sorted);
void	index_stack(t_stack *stack);
int	it_is_sorted(t_stack *stack);

void	swapping_bonus(t_stack *stack);
void rr_li_bghit_bonus(t_stack *stack);
void	p_li_bghit_bonus(t_stack *x, t_stack *y);
void	rotate_bonus(t_stack *stack);


void	free_stuf(char	**spl);
void	free_nodes(t_data	*data);

void	operations(t_data *data);

#endif