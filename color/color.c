/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:27:43 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 12:16:44 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		assign_new_color(int color[3], t_light *li, t_object *obj, t_vec pt)
{
	int			clr_obj[3];
	double		intensity[3];
	t_vec		n;
	t_vec		l;

	n = get_normal(obj, pt, g_rt.cam->coo);
	get_color_object(clr_obj, obj);
	l = ope(li->coo, '-', pt);
	get_intensity(intensity, li, l);
	color[0] += ope_color(clr_obj[0], n, l, intensity[0]);
	color[1] += ope_color(clr_obj[1], n, l, intensity[1]);
	color[2] += ope_color(clr_obj[2], n, l, intensity[2]);
	if (color[0] > clr_obj[0])
		color[0] = clr_obj[0];
	if (color[1] > clr_obj[1])
		color[1] = clr_obj[1];
	if (color[2] > clr_obj[2])
		color[2] = clr_obj[2];
}

void		get_other_lights(t_vec pt, t_object *obj, int color[3])
{
	t_light		*li;
	t_vec		n;

	li = NULL;
	n = get_normal(obj, pt, g_rt.cam->coo);
	while ((li = get_next_light(li)))
	{
		if (dot(ope(pt, '-', li->coo), n) >= 0)
			continue ;
		if (is_obj_between(ope(pt, '-', li->coo), li->coo, obj))
			continue ;
		assign_new_color(color, li, obj, pt);
	}
	return ;
}

int			get_color_light(t_vec pt, t_object *obj)
{
	int		color[3];
	int		color_obj[3];

	if (!obj)
		return (10);
	get_color_object(color_obj, obj);
	if (obj->type == 'l')
	{
		if (obj == g_rt.on_focus)
			on_focus_color(color_obj);
		return (get_color_hexa(color_obj));
	}
	get_ambiant_color(color, color_obj);
	if (g_rt.a_color[0] + g_rt.a_color[1] + g_rt.a_color[2] == 765 &&
			g_rt.a_pwr == 1.0)
	{
		if (obj == g_rt.on_focus)
			on_focus_color(color);
		return (get_color_hexa(color));
	}
	get_other_lights(pt, obj, color);
	if (obj == g_rt.on_focus)
		on_focus_color(color);
	return (get_color_hexa(color));
}
