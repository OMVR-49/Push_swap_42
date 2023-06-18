/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:37:24 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 12:47:51 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../liibft/libft.h"
# include "get_next_line/get_next_line.h"
# include <limits.h>
# include <unistd.h>

typedef struct stack_s
{
	t_list	*head;
}			t_stack;

typedef struct data_s
{
	t_stack	*a;
	t_stack	*b;
}			t_data;

int			initialize(t_data *data);
int			check_dup(int n, t_list *stack);
int			integers(char *str);
int			initialize(t_data *data);
void		ft_parcing(char **argv, t_data *data);

int			get_index(int value, int *numbers, int size);
void		sort_tab(int size, int *number_sorted);
void		index_stack(t_stack *stack);
int			it_is_sorted(t_stack *stack);

void		swapping_bonus(t_stack *stack);
void		rr_li_bghit_bonus(t_stack *stack);
void		p_li_bghit_bonus(t_stack *x, t_stack *y);
void		rotate_bonus(t_stack *stack);

int			ft_strcmp(char *s1, char *s2);

void		free_stuf(char **spl);
void		free_nodes(t_data *data);

void		operations(t_data *data);

void		doubleeee(t_data *data, int a);

void		ft_error(int a);

#endif