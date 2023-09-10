/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:30:28 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 17:59:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		cross(t_vec s, t_vec t)
{
	t_vec		f;

	f.x = s.y * t.z - s.z * t.y;
	f.y = s.z * t.x - s.x * t.z;
	f.z = s.x * t.y - s.y * t.x;
	return (f);
}

double		dot(t_vec f, t_vec s)
{
	return (f.x * s.x + f.y * s.y + f.z * s.z);
}

void		refresh_vector(t_camera *c)
{
	t_vec	v;

	v = c->vector;
	c->vector.x = cos(c->rho) * sin(c->phi);
	c->vector.y = sin(c->rho) * sin(c->phi);
	c->vector.z = cos(c->phi);
	if (fabs(c->vector.x - v.x) > fabs(c->vector.x) &&
		fabs(c->vector.y - v.y) > fabs(c->vector.y) &&
		fabs(c->vector.z - v.z) > fabs(c->vector.z))
	{
		c->vector = ope_num(c->vector, '*', -1);
	}
	c->two_vector = setup_two_vector(c->phi, c->rho);
	c->three_vector = setup_three_vector(c->phi, c->rho);
}

t_vec		setup_two_vector(double phi, double rho)
{
	t_vec		vector;

	if (phi < 0)
	{
		vector.x = cos(rho) * sin(phi + PI / 2);
		vector.y = sin(rho) * sin(phi + PI / 2);
		vector.z = cos(phi + PI / 2);
	}
	else
	{
		vector.x = cos(rho) * sin(phi - PI / 2);
		vector.y = sin(rho) * sin(phi - PI / 2);
		vector.z = cos(phi - PI / 2);
	}
	return (normalize_vector(vector));
}

t_vec		setup_three_vector(double phi, double rho)
{
	t_vec	f;
	t_vec	s;
	t_vec	vector;

	f.x = cos(rho) * sin(phi);
	f.y = sin(rho) * sin(phi);
	f.z = cos(phi);
	s.x = cos(rho) * sin(phi - PI / 4);
	s.y = sin(rho) * sin(phi - PI / 4);
	s.z = cos(phi - PI / 4);
	vector.x = -1 * (f.y * s.z - f.z * s.y);
	vector.y = -1 * (f.z * s.x - f.x * s.z);
	vector.z = -1 * (f.x * s.y - f.y * s.x);
	return (normalize_vector(vector));
}
