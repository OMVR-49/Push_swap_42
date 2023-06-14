/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:38:48 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/14 02:58:04 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include "./liibft/libft.h"

typedef struct stack_s
{
	t_list *head;
} t_stack;

typedef struct data_s
{
	t_stack *a;
	t_stack *b;
} t_data;

void	rotate(t_stack *stack, int a);
void	swapping(t_stack *stack, int a);
void	rr_li_bghit(t_stack *stack, int a);
void	p_li_bghit(t_stack *x, t_stack *y, int a);

int	get_index(int value, int *numbers, int size);
void	sort_tab(int size, int *number_sorted);
void	index_stack(t_stack *stack);
int	it_is_sorted(t_stack *stack);

void	sorting(t_data	*data);
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_min(t_data *data);
void	print_stack(t_data *data);
void	algo_from_a_to_b(t_data *data);
void	algo_from_b_to_a(t_data *data);

#endif 