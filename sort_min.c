/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:52:58 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/14 06:10:21 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	swapping(data->a, 1);
}
int min(t_data *data, int value)
{
	t_list	*head;
	int		min;

	head = data->a->head;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != value)
			min = head->index;
	}
	return (min);
}

void	sort_three(t_data *data)
{
	t_list	*t;
	int		min_in;
	int		next_min_in;

	t = data->a->head;
	min_in = min(data, -1);
	next_min_in = min(data, min_in);
	if (t->next->index == min_in)
		rotate(data->a, 1);
	else
	{
		swapping(data->a, 1);
		rr_li_bghit(data->a, 1);
	}
}

void	sort_min(t_data *data)
{
	
}