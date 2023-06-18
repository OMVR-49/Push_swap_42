/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:38:34 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 12:37:07 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *data)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = data->a->head;
	current_b = data->b->head;
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			printf("%4d a", current_a->val);
			current_a = current_a->next;
		}
		if (current_b != NULL)
		{
			printf("%4d b", current_b->val);
			current_b = current_b->next;
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 0)
	{
		initialize(&data);
		ft_parcing(argv, &data);
		index_stack(data.a);
		if (it_is_sorted(data.a))
		{
			free_nodes(&data);
			free(data.a);
			free(data.b);
			return (0);
		}
		sorting(&data);
	}
	else
		return (0);
	free_nodes(&data);
	free(data.a);
	free(data.b);
}
