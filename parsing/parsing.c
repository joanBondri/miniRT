/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:44:45 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 14:02:43 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void		setup_vector_cam(t_camera *c)
{
	if (c->vector.x == 0 && c->vector.y == 0)
	{
		c->rho = 0;
		if (c->vector.z > 0)
			c->phi = 0;
		else
			c->phi = PI;
	}
	else
	{
		if (c->vector.y == 0 && c->vector.x < 0)
			c->rho = PI;
		else
			c->rho = atan(c->vector.y / c->vector.x);
		c->phi = sqrt(pow(c->vector.x, 2) + pow(c->vector.y, 2));
		c->phi = atan((c->phi) / c->vector.z);
	}
	c->d = -1;
	refresh_vector(c);
}

void		assign_camera(void)
{
	int			len_array;
	t_camera	*c;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 4)
		ft_exit("Error 22 : bad number of parameter in 'c'", 12);
	if (!(c = (t_camera*)ft_malloc(sizeof(t_camera) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	c->coo = get_coordinate(g_rt.data[1]);
	c->vector = get_vector(g_rt.data[2]);
	c->fov = ft_atoi_i(g_rt.data[3]);
	if (c->fov <= 0 || c->fov > 180)
	{
		free(c);
		ft_exit("Error 22 : wrong fov", 1);
	}
	setup_vector_cam(c);
	add_item_list(c, (t_list**)&(g_rt.cameras));
}

void		assign_amblight(void)
{
	int		len_array;

	len_array = len_tab_string(g_rt.data);
	if (len_array != 3 || g_rt.a_pwr != -1)
	{
		if (g_rt.a_pwr != -1)
			ft_exit("Error 22 : duplicate A parameter", 22);
		ft_exit("Error 22 : wrong input in A line", 22);
	}
	g_rt.a_pwr = ft_atoi_f_secur(g_rt.data[1]);
	if (g_rt.a_pwr < 0.0 || g_rt.a_pwr > 1.0)
		ft_exit("Error 22 : wrong power of light", 22);
	get_color(g_rt.data[2], g_rt.a_color);
}

char		**parse_file(int fd)
{
	char	*s;
	char	**res;
	int		gnl_res;

	gnl_res = get_next_line(fd, &s);
	while (gnl_res == 1 && s && !s[0])
	{
		if (s)
			free(s);
		s = NULL;
		gnl_res = get_next_line(fd, &s);
	}
	if (!gnl_res || gnl_res == -1)
	{
		free(s);
		return (NULL);
	}
	if (!s)
		ft_exit("Error 22 : Wrong content file", 22);
	res = ft_split(s, " \t");
	free(s);
	if (!res)
		ft_exit("Error 12 : Cannot allocate memory", 12);
	return (res);
}
