/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:18:48 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/18 12:48:33 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

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

void	ft_parcing(char **argv, t_data *data)
{
	char	**spl;
	int		i;
	int		j;
	int		number;

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

void	ft_error(int a)
{
	if (a == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (a == 0)
		exit(0);
}
