/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:13:59 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:56:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			translation_cam_2(int keycode)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = g_rt.cam->two_vector;
	if (keycode == 106)
	{
		buff1 = ope_num(g_rt.cam->three_vector, '*', tan(PI / 4));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 4));
		g_rt.cam->two_vector = normalize_vector(ope(buff, '-', buff1));
		g_rt.cam->three_vector = normalize_vector(ope(g_rt.cam->three_vector,
					'-', buff2));
	}
}

static void			translation_cam_1(int keycode)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = g_rt.cam->vector;
	if (keycode == 65362)
	{
		buff1 = ope_num(g_rt.cam->two_vector, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		g_rt.cam->vector = normalize_vector(ope(buff, '-', buff1));
		g_rt.cam->two_vector = normalize_vector(ope(g_rt.cam->two_vector,
					'-', buff2));
	}
	else if (keycode == 65364)
	{
		buff1 = ope_num(g_rt.cam->two_vector, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		g_rt.cam->vector = normalize_vector(ope(buff, '+', buff1));
		g_rt.cam->two_vector = normalize_vector(ope(g_rt.cam->two_vector,
					'+', buff2));
	}
	else
		translation_cam_2(keycode);
}

static void			translation_cam(int keycode)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = g_rt.cam->vector;
	if (keycode == 65363)
	{
		buff1 = ope_num(g_rt.cam->three_vector, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		g_rt.cam->vector = normalize_vector(ope(buff, '+', buff1));
		g_rt.cam->three_vector = normalize_vector(ope(g_rt.cam->three_vector,
					'+', buff2));
	}
	else if (keycode == 65361)
	{
		buff1 = ope_num(g_rt.cam->three_vector, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		g_rt.cam->vector = normalize_vector(ope(buff, '-', buff1));
		g_rt.cam->three_vector = normalize_vector(ope(g_rt.cam->three_vector,
					'-', buff2));
	}
	else
		translation_cam_1(keycode);
}

int					mouvement_cam(int keycode)
{
	if (keycode == 119)
		g_rt.cam->coo = ope(g_rt.cam->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		g_rt.cam->coo = ope(g_rt.cam->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		g_rt.cam->coo = ope(g_rt.cam->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		g_rt.cam->coo = ope(g_rt.cam->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		g_rt.cam->coo = ope(g_rt.cam->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		g_rt.cam->coo = ope(g_rt.cam->coo, '-', g_rt.cam->three_vector);
	else if (keycode == 110)
		g_rt.cam = get_next_cam(g_rt.cam);
	else
		translation_cam(keycode);
	return (0);
}
