/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:23:29 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:56:22 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			translation_cam_1(int keycode, t_plane *pl)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = pl->vector;
	if (keycode == 65362)
	{
		buff1 = ope_num(pl->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		pl->vector = normalize_vector(ope(buff, '-', buff1));
		pl->vector1 = normalize_vector(ope(pl->vector1, '-', buff2));
	}
	else if (keycode == 65364)
	{
		buff1 = ope_num(pl->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		pl->vector = normalize_vector(ope(buff, '+', buff1));
		pl->vector1 = normalize_vector(ope(pl->vector1, '+', buff2));
	}
}

static void			translation_cam(int keycode, t_plane *pl)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = pl->vector;
	if (keycode == 65363)
	{
		buff1 = ope_num(pl->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		pl->vector = normalize_vector(ope(buff, '+', buff1));
		pl->vector2 = normalize_vector(ope(pl->vector2, '+', buff2));
	}
	else if (keycode == 65361)
	{
		buff1 = ope_num(pl->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		pl->vector = normalize_vector(ope(buff, '-', buff1));
		pl->vector2 = normalize_vector(ope(pl->vector2, '-', buff2));
	}
	else
		translation_cam_1(keycode, pl);
}

void				mouvement_plane(int keycode, t_plane *pl)
{
	if (keycode == 119)
		pl->coo = ope(pl->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		pl->coo = ope(pl->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		pl->coo = ope(pl->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		pl->coo = ope(pl->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		pl->coo = ope(pl->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		pl->coo = ope(pl->coo, '-', g_rt.cam->three_vector);
	else
		translation_cam(keycode, pl);
}
