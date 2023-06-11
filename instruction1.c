/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:55:14 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/10 16:10:20 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(t_stack *stack, int a)
{
	t_list *tmp;

	tmp = stack->head->next;
	stack->head->next = stack->head->next->next;
	tmp->next = stack->head;
	stack->head = tmp;
	if(a == 1)
		write(1,"sa", 2);
	else if (a == 2)
		write(1,"sb", 2);
}

void rotate(t_stack *stack, int a)
{
	t_list *tmp;

	tmp = stack->head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack->head;
	while(stack->head->next != tmp)
		stack->head = stack->head->next;
	stack->head->next = NULL;
	stack->head = tmp;
	if(a == 1)
		write(1,"sa", 2);
	else if (a == 2)
		write(1,"sb", 2);
}

void	p_li_bghit(t_stack *x, t_stack *y, int a)
{
	t_list *tmp;

	tmp = x->head;
	x->head = x->head->next;
	tmp->next = y->head;
	y->head = tmp;
	if(a == 1)
		write(1,"sa", 2);
	else if (a == 2)
		write(1,"sb", 2);
}

void	rr(t_stack *stack, int a)
{
	t_list	*tmp;

	tmp = stack->head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack->head;
	stack->head = stack->head->next;
	tmp->next->next = NULL;
	if(a == 1)
		write(1,"sa", 2);
	else if (a == 2)
		write(1,"sb", 2);
}