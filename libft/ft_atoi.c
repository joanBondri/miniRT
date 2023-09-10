/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:16:44 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/18 16:43:53 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_white_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' ||
			c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;
	char	*s;

	s = (char*)str;
	res = 0;
	i = 0;
	sign = 1;
	while (is_white_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (sign * res);
}
