/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:37:32 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 17:47:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	in_square(t_vec p, double t, t_square *sq)
{
	double		d1;
	double		d2;
	t_vec		vec_d;

	vec_d = ope(sq->coo, '-', p);
	d1 = dot(sq->vector1, vec_d);
	d2 = dot(sq->vector2, vec_d);
	if (d1 > sq->border / 2 || d1 < -1 * (sq->border / 2)
			|| d2 > sq->border / 2 || d2 < -1 * (sq->border / 2))
		return (-1);
	return (t);
}

double			col_square(t_vec ray, t_vec coo, t_square *sq)
{
	t_vec		l;
	double		sup;
	double		inf;

	l = ope(sq->coo, '-', coo);
	sup = scalaire(l, sq->vector);
	inf = scalaire(sq->vector, ray);
	if (inf == 0 || sup / inf < 0)
		return (-1);
	return (in_square(gen_p(coo, ray, sup / inf), sup / inf, sq));
}
