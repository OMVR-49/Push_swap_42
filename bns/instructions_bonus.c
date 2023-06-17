/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:33:56 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:40:22 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swapping_bonus(t_stack *stack)
{
	t_list *tmp;

	tmp = stack->head->next;
	stack->head->next = stack->head->next->next;
	tmp->next = stack->head;
	stack->head = tmp;
}

void rr_li_bghit_bonus(t_stack *stack)
{
	t_list *tmp;
	int size;

	size = ft_lstsize(stack->head);
		tmp = stack->head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = stack->head;
		while(stack->head->next != tmp)
			stack->head = stack->head->next;
		stack->head->next = NULL;
		stack->head = tmp;
}

void	p_li_bghit_bonus(t_stack *x, t_stack *y)
{
	t_list *tmp;
	if (x->head == NULL)
		return ;
	tmp = x->head;
	x->head = x->head->next;
	tmp->next = y->head;
	y->head = tmp;
}

void	rotate_bonus(t_stack *stack)
{
	t_list	*tmp;
	int size;

	if(!stack->head->next)
		return ;
	size = ft_lstsize(stack->head);
	if (size > 1)
	{
		tmp = stack->head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = stack->head;
		stack->head = stack->head->next;
		tmp->next->next = NULL;
	}
	else
		return;
}