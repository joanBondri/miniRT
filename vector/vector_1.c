/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:41:48 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:37:23 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	ope_num2(t_vec s, char c, double n)
{
	t_vec		f;

	f.x = 0;
	f.y = 0;
	f.z = 0;
	if (c == '*')
	{
		f.x = s.x * n;
		f.y = s.y * n;
		f.z = s.z * n;
	}
	else if (c == '/')
	{
		if (n == 0)
			return (f);
		f.x = s.x / n;
		f.y = s.y / n;
		f.z = s.z / n;
	}
	return (f);
}

t_vec			ope_num(t_vec s, char c, double n)
{
	t_vec		f;

	f.x = 0;
	f.y = 0;
	f.z = 0;
	if (c == '-')
	{
		f.x = s.x - n;
		f.y = s.y - n;
		f.z = s.z - n;
	}
	else if (c == '+')
	{
		f.x = s.x + n;
		f.y = s.y + n;
		f.z = s.z + n;
	}
	else
		return (ope_num2(s, c, n));
	return (f);
}
