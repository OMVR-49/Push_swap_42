/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:18:46 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:19:22 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stuf(char	**spl)
{
	int i;
	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl[i]);
	free(spl);
	spl[i] = NULL;
}

int	check_dup(int n, t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->val == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	integers(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	initialize(t_data *data)
{
	data->a = malloc(sizeof(t_stack));
	if (!data->a)
		return (0);
	data->b = malloc(sizeof(t_stack));
	if (!data->b)
		return (0);
	data->a->head = NULL;
	data->b->head = NULL;
	return (1);
}

void	free_nodes(t_data	*data)
{
	while (data->a->head)
	{
		free(data->a->head);
		data->a->head = data->a->head->next;
	}
	
}

