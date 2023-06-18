/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:55:15 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 12:41:03 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*handelr(char *str)
{
	int		a;
	int		b;
	char	cpy[ft_strlen(str) + 2];
	char	*s;

	a = 1;
	b = 0;
	cpy[0] = '-';
	cpy[ft_strlen(str) + 1] = 0;
	while (str[b])
		cpy[a++] = str[b++];
	s = cpy;
	return (s);
}

void	check_int(char *spl)
{
	size_t	a;

	a = 0;
	if ((spl[a] == '-' || spl[a] == '+') && spl[a + 1] == 48)
		a++;
	while (spl[a] == 48)
		a++;
	if (spl[0] == '-' && spl[1] == 48)
	{
		spl = handelr(spl + a);
		a = 0;
	}
	if (a == ft_strlen(spl))
		return ;
	if (ft_strlen(spl + a) > ft_strlen("-2147483648"))
		ft_error(1);
	if (ft_atoi(spl + a) > INT_MAX || ft_atoi(spl + a) < INT_MIN)
		ft_error(1);
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

void	ft_parcing(char **argv, t_data *data)
{
	char	**spl;
	int		number;
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		spl = ft_split(argv[i], ' ');
		if (spl == NULL || *spl == NULL)
			ft_error(1);
		while (spl[j])
		{
			if (integers(spl[j]))
				ft_error(1);
			check_int(spl[j]);
			number = ft_atoi(spl[j]);
			if (check_dup(number, data->a->head))
				ft_error(1);
			ft_lstadd_back(&data->a->head, ft_lstnew(number));
			j++;
		}
		free_stuf(spl);
	}
}
