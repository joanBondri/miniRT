/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:48:42 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 17:53:57 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			get_vect(t_vec f, t_vec s, t_vec t)
{
	t_vec	result;
	t_vec	v1;
	t_vec	v2;

	v1 = ope(f, '-', s);
	v2 = ope(t, '-', s);
	result = cross(v1, v2);
	if (result.x == 0 && result.y == 0 && result.z == 0)
	{
		v1 = ope(f, '-', t);
		result = cross(v1, v2);
	}
	result = normalize_vector(result);
	return (result);
}

static t_vec	sign(t_vec p1, t_vec p2, t_vec p3)
{
	t_vec	w;
	t_vec	u;

	w = ope(p3, '-', p2);
	u = ope(p1, '-', p2);
	return (cross(w, u));
}

static double	in_triangle(t_vec pt, t_vec v1, t_vec v2, t_vec v3)
{
	t_vec	d1;
	t_vec	d2;
	t_vec	d3;

	d1 = sign(pt, v1, v2);
	d2 = sign(pt, v2, v3);
	d3 = sign(pt, v3, v1);
	if (dot(d1, d2) > 0 && dot(d3, d1) > 0 && dot(d2, d3) > 0)
		return (true);
	return (false);
}

double			col_triangle(t_vec ray, t_vec coo, t_triangle *tr)
{
	t_vec		l;
	double		sup;
	double		inf;
	t_vec		vec;

	vec = get_vect(tr->first_coo, tr->second_coo, tr->third_coo);
	l = ope(tr->first_coo, '-', coo);
	sup = scalaire(l, vec);
	inf = scalaire(vec, ray);
	if (inf == 0 || sup / inf < 0)
		return (-1);
	if (in_triangle(gen_p(coo, ray, sup / inf),
				tr->first_coo, tr->second_coo, tr->third_coo))
		return (sup / inf);
	return (-1);
}
