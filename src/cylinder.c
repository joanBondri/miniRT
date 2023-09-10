/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:05:14 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:36:52 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

double			find_solution(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (-1);
	t1 = (-1 * b - sqrt(delta)) / (2 * a);
	t2 = (-1 * b + sqrt(delta)) / (2 * a);
	if (t1 < 0)
		return (t2);
	return (t1);
}

static double	col_caps_cylinder(t_vec ray, t_vec coo, t_cylinder *cy)
{
	double	t1;
	double	t2;
	double	v;
	double	bot;
	t_vec	p;

	bot = dot(cy->vector, ray);
	if (!bot)
		return (-1);
	v = -1 * dot(cy->vector, ope(coo, '-', cy->coo));
	t1 = v / bot;
	v = -1 * dot(cy->vector,
			ope(coo, '-', gen_p(cy->coo, cy->vector, cy->heigth)));
	t2 = v / bot;
	p = gen_p(coo, ray, t1);
	if (t1 >= 0 && dot(ope(p, '-', cy->coo),
				ope(p, '-', cy->coo)) >= pow((cy->diameter / 2), 2))
		t1 = -1;
	p = gen_p(coo, ray, t2);
	p = ope(p, '-', gen_p(cy->coo, cy->vector, cy->heigth));
	if (t2 >= 0 && dot(p, p) >= pow((cy->diameter / 2), 2))
		t2 = -1;
	if (t1 >= 0 && (t2 < 0 || t1 < t2))
		return (t1);
	return (t2);
}

static double	is_point_in_range(t_vec ray, t_vec coo,
		t_cylinder *cy, double t)
{
	t_vec	p;
	t_vec	q2;

	if (t < 0)
		return (t);
	p = gen_p(coo, ray, t);
	q2 = gen_p(cy->coo, cy->vector, cy->heigth);
	if (dot(cy->vector, ope(p, '-', cy->coo)) < 0)
		return (-1);
	if (dot(cy->vector, ope(p, '-', q2)) > 0)
		return (-1);
	return (t);
}

double			col_cylinder(t_vec ray, t_vec coo, t_cylinder *cy)
{
	t_vec	s;
	t_vec	f;
	double	sol[3];
	double	t2;
	double	t;

	f = ope(coo, '-', cy->coo);
	f = ope(f, '-', ope_num(cy->vector, '*', dot(f, cy->vector)));
	s = ope(ray, '-', ope_num(cy->vector, '*', dot(ray, cy->vector)));
	sol[0] = dot(s, s);
	sol[1] = 2 * dot(s, f);
	sol[2] = dot(f, f) - pow((cy->diameter / 2), 2);
	t = find_solution(sol[0], sol[1], sol[2]);
	t = is_point_in_range(ray, coo, cy, t);
	t2 = col_caps_cylinder(ray, coo, cy);
	if (t >= 0 && (t2 < 0 || t < t2))
		return (t);
	return (t2);
}
