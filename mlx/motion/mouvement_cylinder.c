/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:20:31 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:42:16 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			translation_cam_1(int keycode, t_cylinder *cy)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = g_rt.cam->vector;
	if (keycode == 65362)
	{
		buff = cy->vector;
		buff1 = ope_num(cy->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		cy->vector = normalize_vector(ope(buff, '-', buff1));
		cy->vector1 = normalize_vector(ope(cy->vector1, '-', buff2));
	}
	else if (keycode == 65364)
	{
		buff = cy->vector;
		buff1 = ope_num(cy->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		cy->vector = normalize_vector(ope(buff, '+', buff1));
		cy->vector1 = normalize_vector(ope(cy->vector1, '+', buff2));
	}
}

static void			translation_cam(int keycode, t_cylinder *cy)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = g_rt.cam->vector;
	if (keycode == 65363)
	{
		buff = cy->vector;
		buff1 = ope_num(cy->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		cy->vector = normalize_vector(ope(buff, '+', buff1));
		cy->vector2 = normalize_vector(ope(cy->vector2, '+', buff2));
	}
	else if (keycode == 65361)
	{
		buff = cy->vector;
		buff1 = ope_num(cy->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		cy->vector = normalize_vector(ope(buff, '-', buff1));
		cy->vector2 = normalize_vector(ope(cy->vector2, '-', buff2));
	}
	else
		translation_cam_1(keycode, cy);
}

void				mouvement_cylinder(int keycode, t_cylinder *cy)
{
	if (keycode == 65451)
	{
		cy->diameter += 0.5;
		cy->heigth += 0.5;
	}
	else if (keycode == 65453 && cy->diameter > 0.5 && cy->heigth > 0.5)
	{
		cy->diameter -= 0.5;
		cy->heigth -= 0.5;
	}
	if (keycode == 119)
		cy->coo = ope(cy->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		cy->coo = ope(cy->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		cy->coo = ope(cy->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		cy->coo = ope(cy->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		cy->coo = ope(cy->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		cy->coo = ope(cy->coo, '-', g_rt.cam->three_vector);
	else
		translation_cam(keycode, cy);
}
