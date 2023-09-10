/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:26:07 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:11:32 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*past;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		past = *lst;
		*lst = past->next;
		free(past);
	}
	*lst = NULL;
}
