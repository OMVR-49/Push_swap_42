/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/14 04:09:43 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_data *data)
{
	int size;
	size = ft_lstsize(data->a->head);
	if(size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size == 4 || size == 5)
		sort_min(data);
	else
	{
		algo_from_a_to_b(data);
		algo_from_b_to_a(data);
	}
}

void	algo_from_a_to_b(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = ft_lstsize(data->a->head) / 10;
	while (data->a->head)
	{
		if (data->a->head->index <= i)
		{
			p_li_bghit(data->a, data->b, 1);
			i++;
		}
		else if (data->a->head->index <= i + j)
		{
			p_li_bghit(data->a, data->b, 1);
			rotate(data->b, 2);
			i++;
		}
		else
		{
			rotate(data->a, 1);
		}
	}
}


t_list	*ft_max(t_stack *b)
{
	t_list	*tmp;
	t_list	*max;

	tmp = b->head;
	max = tmp;
	while (tmp)
	{
		if (max->index < tmp->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	initialize_index(t_stack *stack_b)
{
	int		i;
	t_list	*tmp;

	tmp = stack_b->head;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	algo_from_b_to_a(t_data *data)
{
	t_list	*max;
	int		j;

	// initialize_index(data->b);
	j = ft_lstsize(data->b->head);
	while (data->b->head)
	{
		max = ft_max(data->b);
		while (max != data->b->head)
		{
			if (data->b->head->index <= j)
				rr_li_bghit(data->b, 2);
			else
				rotate(data->b, 2);
		}
		p_li_bghit(data->b, data->a, 2);
		j--;
	}
}
