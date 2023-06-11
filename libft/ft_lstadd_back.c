/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:05:40 by ojebbari          #+#    #+#             */
/*   Updated: 2023/06/03 23:34:57 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*oho;

	oho = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (oho->next != NULL)
			oho = oho->next;
		oho->next = new;
	}
}
