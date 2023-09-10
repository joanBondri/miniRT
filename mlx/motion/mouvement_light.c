/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:20:39 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:42:27 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mouvement_light(int keycode, t_light *li)
{
	if (keycode == 119)
		li->coo = ope(li->coo, '+', g_rt.cam->vector);
	else if (keycode == 115)
		li->coo = ope(li->coo, '-', g_rt.cam->vector);
	else if (keycode == 120)
		li->coo = ope(li->coo, '+', g_rt.cam->two_vector);
	else if (keycode == 122)
		li->coo = ope(li->coo, '-', g_rt.cam->two_vector);
	else if (keycode == 100)
		li->coo = ope(li->coo, '+', g_rt.cam->three_vector);
	else if (keycode == 97)
		li->coo = ope(li->coo, '-', g_rt.cam->three_vector);
}
