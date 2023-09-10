/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:08:51 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:51:52 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_malloc(size_t si)
{
	void	*elem;

	if (!(elem = malloc(si)))
		return (NULL);
	ft_lstadd_front(g_mem_lst, mem_list_init(elem));
	return (elem);
}
