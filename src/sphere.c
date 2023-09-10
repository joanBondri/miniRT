/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:24:16 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 17:44:03 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double		col_sphere(t_vec ray, t_vec coo, t_sphere *sp)
{
	t_vec		l;
	double		d;
	double		tca;
	double		tch;

	l = ope(sp->coo, '-', coo);
	tca = scalaire(l, ray);
	d = scalaire(l, l) - tca * tca;
	if (d < 0)
		return (-2);
	d = sqrt(d);
	tch = pow(sp->r, 2) - pow(d, 2);
	if (tch < 0)
		return (-3);
	tch = sqrt(tch);
	if (tca - tch > 0)
		return (tca - tch);
	return (tca + tch);
}

double		col_light(t_vec ray, t_vec coo, t_light *li)
{
	t_vec		l;
	double		d;
	double		tca;
	double		tch;

	l = ope(li->coo, '-', coo);
	tca = scalaire(l, ray);
	d = scalaire(l, l) - tca * tca;
	if (d < 0)
		return (-2);
	d = sqrt(d);
	tch = pow(0.3, 2) - pow(d, 2);
	if (tch < 0)
		return (-3);
	tch = sqrt(tch);
	if (tca - tch > 0)
		return (tca - tch);
	return (tca + tch);
}
