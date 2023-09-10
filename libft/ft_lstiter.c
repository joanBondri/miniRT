/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:27:26 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 12:18:57 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		i;

	i = 0;
	if (!f || !lst)
		return ;
	while (lst)
	{
		printf("%i : ", ++i);
		(*f)(lst->content);
		lst = lst->next;
	}
	return ;
}
