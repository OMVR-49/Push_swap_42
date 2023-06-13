/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:38:48 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/13 00:58:20 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libc.h>
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

void	rotate(t_stack *stack);
void	swapping(t_stack *stack);
void	p_li_bghit(t_stack *x, t_stack *y);
void	rr(t_stack *stack);
void	sorting(t_stack	*stack_a);


#endif 