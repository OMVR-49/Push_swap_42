/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:38:34 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/17 23:26:24 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

void	free_nodes(t_data	*data)
{
	while (data->a->head)
	{
		// free(data->a->head->val);
		free(data->a->head);
		// free(data->a->head->index);
		data->a->head = data->a->head->next;
	}
	
}

static int	initialize(t_data *data)
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


static int	integers(char *str)
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

static int	check_dup(int n, t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->val == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

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
static void	ft_parcing(char **argv, t_data *data)
{
	char	**spl;
	int		i;
	int		j;
	int		number;

	i = 1;
	while (argv[i])
	{
		j = 0;
		spl = ft_split(argv[i], ' ');
		if (spl == NULL || *spl == NULL)
			ft_error(1);
		while (spl[j])
		{
			if (integers(spl[j]))
				ft_error(1);
			number = ft_atoi(spl[j]);
			if (check_dup(number, data->a->head))
				ft_error(1);
			ft_lstadd_back(&data->a->head, ft_lstnew(number));
			j++;
		}
		free_stuf(spl);
		i++;
	}
}
void	v(c)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
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
	atexit(v);
}
