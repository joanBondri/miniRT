/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:26:08 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:43:09 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			translation_cam_1(int keycode, t_square *sq)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = sq->vector;
	if (keycode == 65362)
	{
		buff1 = ope_num(sq->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		sq->vector = normalize_vector(ope(buff, '-', buff1));
		sq->vector1 = normalize_vector(ope(sq->vector1, '-', buff2));
	}
	else if (keycode == 65364)
	{
		buff1 = ope_num(sq->vector1, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		sq->vector = normalize_vector(ope(buff, '+', buff1));
		sq->vector1 = normalize_vector(ope(sq->vector1, '+', buff2));
	}
}

static void			translation_cam(int keycode, t_square *sq)
{
	t_vec	buff;
	t_vec	buff1;
	t_vec	buff2;

	buff = sq->vector;
	if (keycode == 65363)
	{
		buff1 = ope_num(sq->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		sq->vector = normalize_vector(ope(buff, '+', buff1));
		sq->vector2 = normalize_vector(ope(sq->vector2, '+', buff2));
	}
	else if (keycode == 65361)
	{
		buff1 = ope_num(sq->vector2, '*', tan(PI / 45));
		buff2 = ope_num(buff, '*', -1 * tan(PI / 45));
		sq->vector = normalize_vector(ope(buff, '-', buff1));
		sq->vector2 = normalize_vector(ope(sq->vector2, '-', buff2));
	}
	else
		translation_cam_1(keycode, sq);
}

void				mouvement_square(int keycode, t_square *sq)
{
	if (keycode == 65451)
		sq->border += 0.5;
	else if (keycode == 65453 && sq->border > 0.5)
		sq->border -= 0.5;
	if (keycode == 119)
		sq->coo = ope(sq->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		sq->coo = ope(sq->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		sq->coo = ope(sq->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		sq->coo = ope(sq->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		sq->coo = ope(sq->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		sq->coo = ope(sq->coo, '-', g_rt.cam->three_vector);
	else
		translation_cam(keycode, sq);
}
