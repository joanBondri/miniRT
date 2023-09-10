/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:19:34 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:44:46 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		get_ambiant_color(int color[3], int color_obj[3])
{
	color[0] = (color_obj[0]) * ((g_rt.a_color[0]) / 255.0) * g_rt.a_pwr;
	color[1] = (color_obj[1]) * ((g_rt.a_color[1]) / 255.0) * g_rt.a_pwr;
	color[2] = (color_obj[2]) * ((g_rt.a_color[2]) / 255.0) * g_rt.a_pwr;
}

t_light		*get_next_light(t_light *actual)
{
	t_list		*list;
	t_object	*o;

	list = g_rt.lights;
	o = (t_object*)list->content;
	if (!o)
		return (NULL);
	if (actual == NULL)
		return ((t_light*)o->content);
	while (list->content)
	{
		o = (t_object*)list->content;
		if (o == NULL)
			return (NULL);
		if (o->content == actual)
			break ;
		list = list->next;
	}
	list = list->next;
	o = (t_object*)list->content;
	if (!o)
		return (NULL);
	return ((t_light*)(o->content));
}

t_object	*get_next_object(t_object *actual)
{
	t_list		*list;

	list = g_rt.objs;
	if (actual == NULL)
		return ((t_object*)list->content);
	while (list)
	{
		if (list->content == NULL)
			return (NULL);
		if (list->content == actual)
			break ;
		list = list->next;
	}
	list = list->next;
	return ((t_object*)list->content);
}

double		inter(t_vec ray, t_vec ori, t_object *obj)
{
	double		res;

	res = -1;
	if (obj->type == 's')
		res = col_sphere(ray, ori, (t_sphere*)obj->content);
	else if (obj->type == 'p')
		res = col_plane(ray, ori, (t_plane*)obj->content);
	else if (obj->type == 'a')
		res = col_square(ray, ori, (t_square*)obj->content);
	else if (obj->type == 't')
		res = col_triangle(ray, ori, (t_triangle*)obj->content);
	else if (obj->type == 'y')
		res = col_cylinder(ray, ori, (t_cylinder*)obj->content);
	return (res);
}
