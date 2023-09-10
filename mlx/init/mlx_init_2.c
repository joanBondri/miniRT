/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:21:54 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:40:16 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		*get_next_cam(t_camera *actual)
{
	t_list		*list;

	list = g_rt.cameras;
	if (actual == NULL)
		return (set_d_cam((t_camera*)list->content));
	while (list)
	{
		if (list->content == NULL)
			return (NULL);
		if (list->content == actual)
			break ;
		list = list->next;
	}
	list = list->next;
	if (list->content == NULL)
		return (set_d_cam((t_camera*)g_rt.cameras->content));
	return (set_d_cam((t_camera*)list->content));
}

t_vec			setup(int i, int j)
{
	double		x;
	double		y;
	double		z;
	t_vec		vec;
	t_camera	*cam;

	cam = g_rt.cam;
	y = (i - g_rt.r[0] / 2);
	z = (j - g_rt.r[1] / 2);
	x = cam->d;
	vec.x = x * cam->vector.x + z * cam->two_vector.x + y * cam->three_vector.x;
	vec.y = x * cam->vector.y + z * cam->two_vector.y + y * cam->three_vector.y;
	vec.z = x * cam->vector.z + z * cam->two_vector.z + y * cam->three_vector.z;
	return (normalize_vector(vec));
}

static t_vec	ope2(t_vec s, char c, t_vec t)
{
	t_vec		f;

	f.x = 0;
	f.y = 0;
	f.z = 0;
	if (c == '*')
	{
		f.x = s.x * t.x;
		f.y = s.y * t.y;
		f.z = s.z * t.z;
	}
	else if (c == '/')
	{
		f.x = s.x / t.x;
		f.y = s.y / t.y;
		f.z = s.z / t.z;
	}
	return (f);
}

t_vec			ope(t_vec s, char c, t_vec t)
{
	t_vec		f;

	f.x = 0;
	f.y = 0;
	f.z = 0;
	if (c == '-')
	{
		f.x = s.x - t.x;
		f.y = s.y - t.y;
		f.z = s.z - t.z;
	}
	else if (c == '+')
	{
		f.x = s.x + t.x;
		f.y = s.y + t.y;
		f.z = s.z + t.z;
	}
	else
		return (ope2(s, c, t));
	return (f);
}

double			scalaire(t_vec f, t_vec s)
{
	return (f.x * s.x + f.y * s.y + f.z * s.z);
}
