/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:14:31 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:53:15 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_rt_param(void)
{
	if (g_rt.r[0] <= 0 || g_rt.r[1] <= 0)
		ft_exit("Error 22 : no resolution specifiate ", 22);
	if (g_rt.a_color[0] < 0 || g_rt.a_color[1] < 0 ||
			g_rt.a_color[2] < 0 || g_rt.a_pwr == -1)
		ft_exit("Error 22 : no ambiante light specifiate ", 22);
	if (g_rt.cameras->content == NULL)
		ft_exit("Error 22 : no camera specifiate ", 22);
}

void	parsing(int fd, bool bmp_bool)
{
	set_rt_null();
	g_rt.bmp = bmp_bool;
	while ((g_rt.data = parse_file(fd)))
		hub_type();
	check_rt_param();
}

void	hub_type(void)
{
	if (!strncmp(g_rt.data[0], "R", 3))
		assign_resolution();
	else if (!strncmp(g_rt.data[0], "A", 3))
		assign_amblight();
	else if (!strncmp(g_rt.data[0], "c", 3))
		assign_camera();
	else if (!strncmp(g_rt.data[0], "l", 3))
		assign_light();
	else if (!strncmp(g_rt.data[0], "sp", 4))
		assign_sphere();
	else if (!strncmp(g_rt.data[0], "sq", 4))
		assign_square();
	else if (!strncmp(g_rt.data[0], "cy", 4))
		assign_cylinder();
	else if (!strncmp(g_rt.data[0], "pl", 4))
		assign_plane();
	else if (!strncmp(g_rt.data[0], "tr", 4))
		assign_triangle();
	else
		ft_exit("Error 22 : wrong indentifier line", 22);
}

void	add_obj_list(void *item, char type)
{
	t_object	*new_obj;

	if (!(new_obj = (t_object*)ft_malloc(sizeof(t_object) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	new_obj->type = type;
	new_obj->content = item;
	add_item_list(new_obj, (t_list**)&(g_rt.objs));
}

void	assign_resolution(void)
{
	int		len_array;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 3 || ft_atoi_i(g_rt.data[1]) < 1
			|| ft_atoi_i(g_rt.data[2]) < 1 || g_rt.r[0] != -1)
	{
		if (g_rt.r[0] != -1)
			ft_exit("Error 22 : duplicate R parameter", 22);
		ft_exit("Error 22 : bad first argument in file", 22);
	}
	g_rt.r[0] = ft_atoi_i(g_rt.data[1]);
	g_rt.r[1] = ft_atoi_i(g_rt.data[2]);
}
