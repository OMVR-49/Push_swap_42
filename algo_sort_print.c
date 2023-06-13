/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/13 02:41:54 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sorting(t_data	*data)
{
	int size;

	size = ft_lstsize(*data->a);
	if ((size == 0) || size == 1)
		exit(0);
	else
		monster_sort(data->a);
}

void	monster_sort(t_stack	*stack_a)
{
	int	max;
	int	i;
	int	j;
	int	lenght;

	i = 0;
	lenght = ft_lstsize(*stack_a);
	j = lenght / 2;
	
}
