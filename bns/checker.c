/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:32:39 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 12:47:35 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op(char *gnl, t_data *data)
{
	if (!ft_strcmp(gnl, "pa\n"))
		p_li_bghit_bonus(data->a, data->b);
	else if (!ft_strcmp(gnl, "pb\n"))
		p_li_bghit_bonus(data->b, data->a);
	else if (!ft_strcmp(gnl, "sa\n"))
		swapping_bonus(data->a);
	else if (!ft_strcmp(gnl, "sb\n"))
		swapping_bonus(data->b);
	else if (!ft_strcmp(gnl, "ra\n"))
		rotate_bonus(data->a);
	else if (!ft_strcmp(gnl, "rb\n"))
		rotate_bonus(data->b);
	else if (!ft_strcmp(gnl, "rra\n"))
		rr_li_bghit_bonus(data->a);
	else if (!ft_strcmp(gnl, "rrb\n"))
		rr_li_bghit_bonus(data->b);
	else if (!ft_strcmp(gnl, "rr\n"))
		doubleeee(data, 1);
	else if (!ft_strcmp(gnl, "rrr\n"))
		doubleeee(data, 2);
	else if (!ft_strcmp(gnl, "ss\n"))
		doubleeee(data, 3);
	else
		ft_error(1);
}

void	operations(t_data *data)
{
	char	*s;

	s = get_next_line(0);
	while (s != NULL)
	{
		s = get_next_line(0);
		check_op(s, data);
	}
	if (it_is_sorted(data->a))
	{
		free_nodes(data);
		write(1, "OK\n", 3);
	}
	else if (!it_is_sorted(data->a))
	{
		free_nodes(data);
		write(1, "KO\n", 3);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 0)
	{
		initialize(&data);
		ft_parcing(argv, &data);
		index_stack(data.a);
		operations(&data);
	}
	free_nodes(&data);
	free(data.a);
	free(data.b);
	return (0);
}
