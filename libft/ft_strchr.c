/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:36:20 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/18 16:36:22 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = -1;
	s = (char *)str;
	while (str[++i])
	{
		if (str[i] == c)
			return (s + i);
	}
	if (c == 0 && s[i] == '\0')
		return (s + i);
	return (NULL);
}
