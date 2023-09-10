/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:19:14 by jbondri           #+#    #+#             */
/*   Updated: 2021/01/28 14:22:18 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		is_obj_between(t_vec ray, t_vec ori, t_object *obj)
{
	t_object	*buff;
	t_vec		n_ray;
	double		res;
	double		dist;

	buff = NULL;
	dist = sqrt(scalaire(ray, ray));
	n_ray = normalize_vector(ray);
	while ((buff = get_next_object(buff)))
	{
		if (buff == obj)
			continue ;
		res = inter(n_ray, ori, buff);
		if (res < dist && res > 0)
			return (true);
	}
	return (false);
}

void		get_color_object(int color_obj[3], t_object *obj)
{
	void	*p;

	p = (void*)obj->content;
	if (obj->type == 's')
		assign_array(color_obj, ((t_sphere*)p)->color);
	else if (obj->type == 'y')
		assign_array(color_obj, ((t_cylinder*)p)->color);
	else if (obj->type == 'a')
		assign_array(color_obj, ((t_square*)p)->color);
	else if (obj->type == 't')
		assign_array(color_obj, ((t_triangle*)p)->color);
	else if (obj->type == 'l')
		assign_array(color_obj, ((t_light*)p)->color);
	else if (obj->type == 'p')
		assign_array(color_obj, ((t_plane*)p)->color);
}

int			ope_color(int obj, t_vec n, t_vec l, double intensity)
{
	double	res;

	res = (obj / (255.0 * PI)) * intensity * (dot(n, l));
	return (res * 255);
}

void		get_intensity(double intensity[3], t_light *li, t_vec l)
{
	double		a;

	a = li->power / (8.0 * PI * sqrt(dot(l, l)));
	intensity[0] = a * li->color[0];
	intensity[1] = a * li->color[1];
	intensity[2] = a * li->color[2];
}
