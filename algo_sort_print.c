/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/17 06:08:36 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_data *data)
{
	int	size;

	size = ft_lstsize(data->a->head);
	if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size == 4)
		sort_four(data);
	else if (size == 5)
		sort_five(data);
	else if (size <= 100)
	{
		algo_from_a_to_b(data, 4);
		algo_from_b_to_a(data);
	}
	else
	{
		algo_from_a_to_b(data, 10);
		algo_from_b_to_a(data);
	}
}

void	algo_from_a_to_b(t_data *data, int z)
{
	int	j;
	int	i;

	i = 0;
	while (data->a->head)
	{
		j = ft_lstsize(data->a->head) / z;
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
			rotate(data->a, 1);
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
		if (max->val < tmp->val)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	initialize_index(t_list *stack_b)
{
	int		i;
	t_list	*tmp;

	tmp = stack_b;
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
	int		size;
	t_list	*tmp;

	initialize_index(data->b->head);
	size = ft_lstsize(data->b->head) - 1;
	while (data->b->head && size >= 0)
	{
		max = ft_max(data->b);
		if (data->b->head == max)
		{
			p_li_bghit(data->b, data->a, 2);
			size--;
			initialize_index(data->b->head);
		}
		else if (max->index >= size / 2)
			rr_li_bghit(data->b, 2);
		else
			rotate(data->b, 2);
	}
}
