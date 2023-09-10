/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:14:42 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/11 16:17:20 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_phi(t_vec vec)
{
	if (vec.x == 0 && vec.y == 0)
	{
		if (vec.z > 0)
			return (0);
		return (PI);
	}
	else if (vec.y == 0 && vec.x < 0)
		return (atan(sqrt(pow(vec.x, 2) + pow(vec.y, 2)) / vec.z));
	return (atan(sqrt(pow(vec.x, 2) + pow(vec.y, 2)) / vec.z));
}

void	assign_plane(void)
{
	int			len_array;
	t_plane		*p;
	double		rho;
	double		phi;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 4)
		ft_exit("Error 22 : bad number of argument in 'pl'", 22);
	if (!(p = (t_plane*)ft_malloc(sizeof(t_plane) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	p->coo = get_coordinate(g_rt.data[1]);
	p->vector = get_vector(g_rt.data[2]);
	phi = get_phi(p->vector);
	rho = get_rho(p->vector);
	p->vector1 = setup_two_vector(phi, rho);
	p->vector2 = setup_three_vector(phi, rho);
	get_color(g_rt.data[3], p->color);
	add_obj_list(p, 'p');
}

void	assign_cylinder(void)
{
	int			len_array;
	t_cylinder	*y;
	double		rho;
	double		phi;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 6)
		ft_exit("Error 22 : bad number of argument in 'cy'", 22);
	if (!(y = (t_cylinder*)ft_malloc(sizeof(t_cylinder) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	y->coo = get_coordinate(g_rt.data[1]);
	y->vector = get_vector(g_rt.data[2]);
	y->diameter = ft_atoi_f_secur(g_rt.data[3]);
	y->heigth = ft_atoi_f_secur(g_rt.data[4]);
	get_color(g_rt.data[5], y->color);
	if (y->heigth <= 0.0 || y->diameter <= 0.0)
	{
		free(y);
		ft_exit("Error 22 : wrong heigth in 'cy'", 22);
	}
	phi = get_phi(y->vector);
	rho = get_rho(y->vector);
	y->vector1 = setup_two_vector(phi, rho);
	y->vector2 = setup_three_vector(phi, rho);
	add_obj_list(y, 'y');
}

void	assign_square(void)
{
	int			len_array;
	double		rho;
	double		phi;
	t_square	*a;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 5)
		ft_exit("Error 22 : bad number of argument in 'sq'", 1);
	if (!(a = (t_square*)ft_malloc(sizeof(t_square) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	a->coo = get_coordinate(g_rt.data[1]);
	a->vector = get_vector(g_rt.data[2]);
	a->border = ft_atoi_f_secur(g_rt.data[3]);
	if (a->border <= 0.0)
	{
		free(a);
		ft_exit("Error 22 : wrong heigth in 'sq'", 1);
	}
	phi = get_phi(a->vector);
	rho = get_rho(a->vector);
	a->vector1 = setup_two_vector(phi, rho);
	a->vector2 = setup_three_vector(phi, rho);
	get_color(g_rt.data[4], a->color);
	add_obj_list(a, 'a');
}
