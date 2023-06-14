/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:21:56 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/14 03:34:40 by ojebbari         ###   ########.fr       */
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
		write(1,"sa\n", 3);
	else if (a == 2)
		write(1,"sb\n", 3);

	
}

void rr_li_bghit(t_stack *stack, int a)
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
		if(a == 1)
			write(1,"rra\n", 4);
		else if (a == 2)
			write(1,"rrb\n", 4);
}

void	p_li_bghit(t_stack *x, t_stack *y, int a)
{
	t_list *tmp;
	if (x->head == NULL)
		return ;
	tmp = x->head;
	x->head = x->head->next;
	tmp->next = y->head;
	y->head = tmp;
	if (a == 1)
		write(1,"pb\n", 3);
	else if (a == 2)
		write(1,"pa\n", 3);

}

void	rotate(t_stack *stack, int a)
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
		if(a == 1)
			write(1,"ra\n", 4);
		else if (a == 2)
			write(1,"rb\n", 4);
	}
	else
		return;
}