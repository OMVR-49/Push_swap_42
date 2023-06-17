/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:32:39 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 00:41:05 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operations(t_data *data)
{	
	(void)data;
	// (void)data;
	// while (line == NULL)
	// {
	// 	break;
	// }
	// if (is_sorted)
	// {
	// 	printf("ok");	
	// }
	// else
	// 	printf("ko");	
	
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
		operations(&data);
	}
	else
		return (0);
	free_nodes(&data);
	free(data.a);
	free(data.b);
}