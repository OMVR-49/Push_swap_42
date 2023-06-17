/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:25:23 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:41:32 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_index(int value, int *numbers, int size)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		if (value == numbers[i])
		{
			index = i;
			break ;
		}
		i++;
	}
	return (index);
}

void	sort_tab(int size, int *number_sorted)
{
	int	j;
	int	k;
	int	temp;

	j = 0;
	while (j < size - 1)
	{
		k = 0;
		while (k < size - j - 1)
		{
			if (number_sorted[k] > number_sorted[k + 1])
			{
				temp = number_sorted[k];
				number_sorted[k] = number_sorted[k + 1];
				number_sorted[k + 1] = temp;
			}
			k++;
		}
		j++;
	}
}

void	index_stack(t_stack *stack)
{
	t_list	*current;
	int		*number_sorted;
	int		size;
	int		i;

	current = stack->head;
	size = ft_lstsize(current);
	number_sorted = malloc(sizeof(int) * size);
	i = 0;
	while (current)
	{
		number_sorted[i] = current->val;
		current = current->next;
		i++;
	}
	sort_tab(size, number_sorted);
	current = stack->head;
	i = 0;
	while (current)
	{
		current->index = get_index(current->val, number_sorted, size);
		current = current->next;
	}
	free(number_sorted);
}

int	it_is_sorted(t_stack *stack)
{
	t_list	*current;
	int	i;

	i = 0;
	current = stack->head;
	while(current)
	{
		if (current->next == NULL)
			break;
		if(current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}
