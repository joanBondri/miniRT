/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_cool_function_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:44:31 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:52:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	decimal(char *dot_str)
{
	double	step;
	double	decimal;

	decimal = (double)ft_atoi(dot_str + 1);
	step = 1;
	while (*(++dot_str) == '0')
		step /= 10;
	if (dot_str == '\0')
		return (0);
	while (decimal >= step)
		decimal /= 10;
	return (decimal);
}

double			ft_atoi_f(char *str)
{
	double	res;
	char	*dot_str;
	int		sign;

	sign = 1;
	dot_str = str;
	if (*dot_str == '-' || *dot_str == '+')
	{
		if (*dot_str == '-')
			sign = -1;
		dot_str++;
	}
	res = (double)ft_atoi(dot_str);
	if (res < 0)
		return (0.0);
	dot_str = afterset(dot_str, "0123456789");
	if (dot_str[0] != '.')
		return (sign * res);
	return (sign * (res + decimal(dot_str)));
}

double			ft_atoi_f_secur(char *s)
{
	char	*str;

	str = s;
	if (*str == '-' || *str == '+')
		str++;
	str = afterset(str, "0123456789");
	if (*str == '.')
		str++;
	str = afterset(str, "0123456789");
	if (*str)
		ft_exit("Error 22 : wrong number (double)", 22);
	return (ft_atoi_f(s));
}

int				ft_atoi_i(char *s)
{
	char	*test;

	test = s;
	if (*test == '-' || *test == '+')
		test++;
	test = afterset(s, "0123456789");
	if (*test)
		ft_exit("Error 22 : wrong number (int)", 22);
	return (ft_atoi(s));
}

char			*afterset(char *source, char *set)
{
	int		i;

	i = 0;
	if (!source || !set)
		return (NULL);
	while (ft_strchr(set, source[i]) && source[i])
		i++;
	return (source + i);
}
