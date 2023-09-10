/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:42:06 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 12:31:44 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	get_norm_sphere(t_sphere *s, t_vec pt)
{
	return (normalize_vector(ope(pt, '-', s->coo)));
}

static t_vec	get_norm_cylinder(t_cylinder *cy, t_vec pt)
{
	t_vec	v;
	t_vec	u;

	if (dot(ope(pt, '-', cy->coo), cy->vector) >= -0.0001 &&
		dot(ope(pt, '-', cy->coo), cy->vector) <= 0.0001)
		return (ope_num(cy->vector, '*', -1));
	if (dot(ope(pt, '-', cy->coo), cy->vector) >= cy->heigth - 0.0001 &&
		dot(ope(pt, '-', cy->coo), cy->vector) <= cy->heigth + 0.0001)
		return (cy->vector);
	u = ope(pt, '-', cy->coo);
	v = cy->vector;
	return (normalize_vector(ope(u, '-', ope_num(v, '*', dot(u, v)))));
}

static t_vec	get_norm_triangle(t_triangle *t)
{
	return (get_vect(t->first_coo, t->second_coo, t->third_coo));
}

t_vec			get_normal(t_object *o, t_vec pt, t_vec coo)
{
	t_vec	res;

	if (o->type == 's')
		res = get_norm_sphere((t_sphere*)o->content, pt);
	else if (o->type == 'y')
		res = get_norm_cylinder((t_cylinder*)o->content, pt);
	else if (o->type == 'a')
		res = ((t_square*)o->content)->vector;
	else if (o->type == 't')
		res = get_norm_triangle((t_triangle*)o->content);
	else
		res = ((t_plane*)o->content)->vector;
	if (dot(ope(pt, '-', coo), res) > 0)
		return (ope_num(res, '*', -1));
	return (res);
}
