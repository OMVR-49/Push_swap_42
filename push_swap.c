/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:38:34 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/13 02:36:28 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

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

static void	ft_parcing(int argc, char **argv, t_data *data)
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
			exit(0xFF);
		while (spl[j])
		{
			if (integers(spl[j]))
				exit(96);
			number = ft_atoi(spl[j]);
			if (check_dup(number, data->a->head))
				exit(69);
			ft_lstadd_back(&data->a->head, ft_lstnew(number));
			j++;
		}
		i++;
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
void	it_is_sorted(t_stack *stack)
{
	t_list	*current;
	int	i;

	i = 0;
	current = stack->head;
	while(stack->head)
	{
		if(current->index > current->next->index)
			return;
		current = current->next;
	}
	exit(0);
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		initialize(&data);
		ft_parcing(argc, argv, &data);
		index_stack(data.a);
		it_is_sorted(&data.a);
		sorting(&data);
		// print_stack(&data);
		// while (data.a->head)
		// {
		// 	printf("number %d [%d]\n",data.a->head->val,data.a->head->index);
		// 	data.a->head = data.a->head->next;
		// }
	}
	else
		return (0);
}

// while
// {
// spl = ft_split(argv);
// while(kador 3la split)
// {
// 	kol wahed w katchof is valid > ft_atoi;
// }
// }
// free(spl);