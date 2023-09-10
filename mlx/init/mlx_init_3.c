/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:21:59 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 14:05:44 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		analyze_next_obj(t_vec ray, t_pixel *data, t_object *obj)
{
	double		res;

	res = -1;
	if (!obj)
		return ;
	if (obj->type == 's')
		res = col_sphere(ray, g_rt.cam->coo, (t_sphere*)obj->content);
	else if (obj->type == 'p')
		res = col_plane(ray, g_rt.cam->coo, (t_plane*)obj->content);
	else if (obj->type == 'a')
		res = col_square(ray, g_rt.cam->coo, (t_square*)obj->content);
	else if (obj->type == 't')
		res = col_triangle(ray, g_rt.cam->coo, (t_triangle*)obj->content);
	else if (obj->type == 'y')
		res = col_cylinder(ray, g_rt.cam->coo, (t_cylinder*)obj->content);
	else if (obj->type == 'l')
		res = col_light(ray, g_rt.cam->coo, (t_light*)obj->content);
	if ((res < data->res && data->res >= 0 && res >= 0)
			|| (res >= 0 && data->res <= 0))
	{
		data->res = res;
		data->obj = obj;
	}
}

void		on_focus_color(int color[3])
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (color[i] < 225)
			color[i] += 30;
		else
			color[i] = 255;
	}
}

void		colision(t_vec ray, t_pixel *data)
{
	t_list		*list;

	list = g_rt.objs;
	data->obj = NULL;
	data->res = -1;
	while (list->content)
	{
		analyze_next_obj(ray, data, (t_object*)list->content);
		list = list->next;
	}
	if (g_rt.show_light)
	{
		list = g_rt.lights;
		while (list->content)
		{
			analyze_next_obj(ray, data, (t_object*)list->content);
			list = list->next;
		}
	}
}

void		next_frame(t_param_frame *obj)
{
	t_vec		ray;
	t_vec		yp;
	t_pixel		data;
	int			i;
	int			j;

	i = -1;
	while (++i < g_rt.r[0])
	{
		j = -1;
		while (++j < g_rt.r[1])
		{
			ray = setup(i, j);
			colision(ray, &data);
			if (data.res == -1)
				data.color = 10;
			else
			{
				yp = gen_p(g_rt.cam->coo, ray, data.res);
				data.color = get_color_light(yp, data.obj);
			}
			my_mlx_pixel_put(obj->img, i, j, data.color);
		}
	}
}

int			clic_image(int keycode, int x, int y, t_param_frame *frame)
{
	t_pixel		data;

	if (keycode == 3)
		g_rt.on_focus = NULL;
	else if (keycode == 1)
	{
		colision(setup(x, y), &data);
		get_color_light(gen_p(g_rt.cam->coo, setup(x, y), data.res),
				data.obj);
		g_rt.on_focus = data.obj;
	}
	next_frame(frame);
	mlx_put_image_to_window(frame->mlx.mlx,
			frame->mlx.mlx_win, frame->img.img, 0, 0);
	return (0);
}
