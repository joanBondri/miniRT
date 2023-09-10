/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:25:44 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 17:46:07 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double		col_plane(t_vec ray, t_vec coo, t_plane *pl)
{
	t_vec		l;
	double		sup;
	double		inf;

	l = ope(pl->coo, '-', coo);
	sup = scalaire(l, pl->vector);
	inf = scalaire(pl->vector, ray);
	if (inf == 0)
		return (-1);
	return (sup / inf);
}
