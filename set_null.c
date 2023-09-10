/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:40:51 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:38:13 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_rt_null(void)
{
	g_rt.r[0] = -1;
	g_rt.r[1] = -1;
	g_rt.a_color[0] = -1;
	g_rt.a_color[1] = -1;
	g_rt.a_color[2] = -1;
	g_rt.a_pwr = -1.0;
	g_rt.bmp = false;
	g_rt.show_light = false;
	g_rt.cam = NULL;
	g_rt.data = NULL;
	g_rt.on_focus = NULL;
	g_rt.cameras = ft_lstnew(NULL);
	g_rt.lights = ft_lstnew(NULL);
	g_rt.objs = ft_lstnew(NULL);
}
