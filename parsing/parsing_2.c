/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:14:37 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:53:24 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		assign_sphere(void)
{
	int			len_array;
	t_sphere	*s;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 4)
		ft_exit("Error 22 : wrong number of argument in 'sp'", 22);
	if (!(s = (t_sphere*)ft_malloc(sizeof(t_sphere) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	s->coo = get_coordinate(g_rt.data[1]);
	s->r = ft_atoi_f_secur(g_rt.data[2]);
	if (s->r <= 0.0)
	{
		free(s);
		ft_exit("Error 22 : wrong r parameter in 'sp'", 22);
	}
	get_color(g_rt.data[3], s->color);
	add_obj_list(s, 's');
}

t_object	*creat_obj(void *data, char type)
{
	t_object	*o;

	if (!(o = ft_malloc(sizeof(t_object) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	o->type = type;
	o->content = data;
	return (o);
}

void		assign_light(void)
{
	int			len_array;
	t_light		*l;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 4)
		ft_exit("Error 22 : wrong number of argument in 'l'", 22);
	if (!(l = (t_light*)ft_malloc(sizeof(t_light) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	l->coo = get_coordinate(g_rt.data[1]);
	l->power = ft_atoi_f_secur(g_rt.data[2]);
	if (l->power < 0.0 || l->power > 1.0)
		ft_exit("Error 22 : wrong power argument in 'l'", 22);
	get_color(g_rt.data[3], l->color);
	add_item_list(creat_obj(l, 'l'), (t_list**)&(g_rt.lights));
}

void		assign_triangle(void)
{
	int			len_array;
	t_triangle	*t;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 5)
		ft_exit("Error 22 : bad number of argument in 'tr'", 22);
	if (!(t = (t_triangle*)ft_malloc(sizeof(t_triangle) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	t->first_coo = get_coordinate(g_rt.data[1]);
	t->second_coo = get_coordinate(g_rt.data[2]);
	t->third_coo = get_coordinate(g_rt.data[3]);
	get_color(g_rt.data[4], t->color);
	add_obj_list(t, 't');
}

double		get_rho(t_vec vec)
{
	if (vec.x == 0 && vec.y == 0)
		return (0);
	else if (vec.y == 0 && vec.x < 0)
		return (PI);
	return (atan(vec.y / vec.x));
}
