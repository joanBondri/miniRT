/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:41:08 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:43:24 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mouvement_triangle_2(int keycode, t_triangle *tr)
{
	if (keycode == 122)
	{
		tr->first_coo = ope(tr->first_coo, '-', g_rt.cam->two_vector);
		tr->second_coo = ope(tr->second_coo, '-', g_rt.cam->two_vector);
		tr->third_coo = ope(tr->third_coo, '-', g_rt.cam->two_vector);
	}
	else if (keycode == 100)
	{
		tr->first_coo = ope(tr->first_coo, '+', g_rt.cam->three_vector);
		tr->second_coo = ope(tr->second_coo, '+', g_rt.cam->three_vector);
		tr->third_coo = ope(tr->third_coo, '+', g_rt.cam->three_vector);
	}
	else if (keycode == 97)
	{
		tr->first_coo = ope(tr->first_coo, '-', g_rt.cam->three_vector);
		tr->second_coo = ope(tr->second_coo, '-', g_rt.cam->three_vector);
		tr->third_coo = ope(tr->third_coo, '-', g_rt.cam->three_vector);
	}
}

void	mouvement_triangle(int keycode, t_triangle *tr)
{
	if (keycode == 119)
	{
		tr->first_coo = ope(tr->first_coo, '+', g_rt.cam->vector);
		tr->second_coo = ope(tr->second_coo, '+', g_rt.cam->vector);
		tr->third_coo = ope(tr->third_coo, '+', g_rt.cam->vector);
	}
	else if (keycode == 115)
	{
		tr->first_coo = ope(tr->first_coo, '-', g_rt.cam->vector);
		tr->second_coo = ope(tr->second_coo, '-', g_rt.cam->vector);
		tr->third_coo = ope(tr->third_coo, '-', g_rt.cam->vector);
	}
	else if (keycode == 120)
	{
		tr->first_coo = ope(tr->first_coo, '+', g_rt.cam->two_vector);
		tr->second_coo = ope(tr->second_coo, '+', g_rt.cam->two_vector);
		tr->third_coo = ope(tr->third_coo, '+', g_rt.cam->two_vector);
	}
	else
		mouvement_triangle_2(keycode, tr);
}
