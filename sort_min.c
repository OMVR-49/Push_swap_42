/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:52:58 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/17 13:01:56 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	swapping(data->a, 1);
}
t_list	*ft_min(t_stack *b)
{
	t_list	*tmp;
	t_list	*min;

	tmp = b->head;
	min = tmp;
	while (tmp)
	{
		if (min->val > tmp->val)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	passage_par_adresse(int *a, int *b, int *c, t_data *d)
{
	*a = d->a->head->val;
	*b = d->a->head->next->val;
	*c = d->a->head->next->next->val;
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	passage_par_adresse(&a, &b, &c, data);
	if (it_is_sorted(data->a))
		return ;
	if (a < b && a < c)
	{
		rr_li_bghit(data->a, 1);
		swapping(data->a, 1);
	}
	else if (a > b && a < c)
		swapping(data->a, 1);
	else if (a < b && a > c)
		rr_li_bghit(data->a, 1);
	else if (a > b && a > c && b < c)
		rotate(data->a, 1);
	else if (a > b && a > c && b > c)
	{
			swapping(data->a, 1);
			rr_li_bghit(data->a, 1);
	}
}

void	sort_four(t_data *data)
{
	t_list	*min;

	min = ft_min(data->a);
	while (1)
	{
		if (data->a->head == min)
		{
			p_li_bghit(data->a, data->b, 1);
			sort_three(data);
			p_li_bghit(data->b, data->a, 2);
			break ;
		}
		else if (min->index > 2)
			rr_li_bghit(data->a, 1);
		else
			rotate(data->a, 1);
	}
}

void	sort_five(t_data *data)
{
	t_list	*min;

	min = data->a->head;
	min = ft_min(data->a);
	while (1)
	{
		if (data->a->head == min)
		{
			p_li_bghit(data->a, data->b, 1);
			sort_four(data);
			p_li_bghit(data->b, data->a, 2);
			break ;
		}
		else if(min->index == data->a->head->next->next->next->next->index)
			rr_li_bghit(data->a, 1);
		else
			rotate(data->a, 1);
	}
}
