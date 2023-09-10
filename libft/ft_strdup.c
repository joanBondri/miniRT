/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:36:42 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:06:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = 0;
	while (s[len])
		len++;
	if (!(res = (char*)ft_malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[++i])
		res[i] = s[i];
	res[len] = '\0';
	return (res);
}
