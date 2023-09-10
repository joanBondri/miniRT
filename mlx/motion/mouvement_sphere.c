/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:20:39 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:42:53 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mouvement_sphere(int keycode, t_sphere *sp)
{
	if (keycode == 65451)
		sp->r += 0.5;
	else if (keycode == 65453)
	{
		if (sp->r > 0.5)
			sp->r -= 0.5;
	}
	if (keycode == 119)
		sp->coo = ope(sp->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		sp->coo = ope(sp->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		sp->coo = ope(sp->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		sp->coo = ope(sp->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		sp->coo = ope(sp->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		sp->coo = ope(sp->coo, '-', g_rt.cam->three_vector);
}
