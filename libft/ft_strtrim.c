/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:41:44 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:07:14 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_in(char c, char *base)
{
	int		i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		buff;
	int		len;
	char	*str;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char *)s1;
	len = ft_strlen((char *)s1);
	i = -1;
	while (str[++i] && is_in(str[i], (char *)set))
		len--;
	i = ft_strlen((char *)s1);
	while (--i >= 0 && is_in(str[i], (char *)set))
		(!len) ? len : len--;
	if (!(res = (char*)ft_malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (str[i] && is_in(str[i], (char *)set))
		i++;
	buff = i--;
	while (++i - buff <= len)
		res[i - buff] = (i - buff == len) ? '\0' : str[i];
	return (res);
}
