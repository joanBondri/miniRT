/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:20:53 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:11:03 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void		**v;
	char		*s;
	size_t		i;

	if (!(v = (void *)ft_malloc(nitems * size)))
		return (NULL);
	s = (char *)v;
	i = 0;
	while (i < nitems * size)
	{
		s[i] = 0;
		i++;
	}
	return (v);
}
