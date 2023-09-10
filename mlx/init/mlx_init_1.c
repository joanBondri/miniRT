/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:21:43 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:49:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		resize(void *mlx)
{
	int		x;
	int		y;

	mlx_get_screen_size(mlx, &x, &y);
	if (g_rt.r[0] > x)
		g_rt.r[0] = x;
	if (g_rt.r[1] > y)
		g_rt.r[1] = y;
	return ;
}

int			get_color_hexa(int tab[3])
{
	return (tab[0] * 65536 + tab[1] * 256 + tab[2]);
}

void		my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	(void)color;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		go_mlx(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	resize(mlx.mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, g_rt.r[0], g_rt.r[1], "miniRT");
	img.img = mlx_new_image(mlx.mlx, g_rt.r[0], g_rt.r[0]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	main_mlx(mlx, img);
}

t_camera	*set_d_cam(t_camera *cam)
{
	if (cam->d != -1)
		return (cam);
	cam->d = g_rt.r[0] / (tan(cam->fov * PI / 360) * 2);
	return (cam);
}
