/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:18:48 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:22:29 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_parcing(char **argv, t_data *data)
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

void ft_error(int a)
 {
	if (a == 1)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	else if (a == 0)
		exit(0);
}

