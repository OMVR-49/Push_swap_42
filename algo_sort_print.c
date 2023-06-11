/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:53:46 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/11 17:02:26 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void	swap(t_stack *x,t_stack *y)
// {
// 	int tmp;

// 	tmp = x.head->val;
// 	x.head->val = y.head->val;
// 	y.head->val = tmp;
// }
void index(t_stack *x)
{
	int i;

	i = 0;
	while(x->head)
	{
		x->head->index = i;
		x->head = x->head->next;
		i++;
	}
}
void sort_index(t_stack *x)
{
	int min;
	t_stack *tmp;

	tmp = x;
	min = 0;
	while(tmp->head != NULL)
	{
		if (tmp->head->val < tmp->head->next->val)
			tmp->head = tmp->head->next;
		
	}
}
void	index_sort(t_stack *stack_a)
{
	int	i;
	int swp;
	t_stack	*ptr;
	t_stack	*lptr;
	t_stack tmp;

	i = 0;
	swp = 1;
	while(swp)
	{
		swp = 0;
		ptr = stack_a;
		lptr = NULL;
		while(ptr->head->next != lptr)
		{
			if(ptr->head->val > ptr->head->next->val)
			{
				swap(ptr->head->val, ptr->head->next->val);
				swp = 1;
			}
			ptr->head = ptr->head->next;
		}
		lptr = ptr;
	}
}

void	sorting(t_stack	*stack_a)
{
	int	max;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while(stack_a->head != NULL)
	{
		l++;
		stack_a->head = stack_a->head->next;
	}
	j = l / 2;
	index(stack_a);
	index_sort(stack_a);
	
}
