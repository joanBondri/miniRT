/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:53:16 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 14:04:42 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	manage_keycode(int keycode, t_param_frame *frame)
{
	if (keycode == 103)
		gen_file();
	if (keycode == 112)
		g_rt.show_light = !(g_rt.show_light);
	if (keycode == 65307)
	{
		mlx_destroy_image(frame->mlx.mlx, frame->img.img);
		mlx_destroy_window(frame->mlx.mlx, frame->mlx.mlx_win);
		ft_exit("", 1);
	}
}

int			move_sth(int keycode, t_param_frame *frame)
{
	t_object	*on;

	on = g_rt.on_focus;
	if (keycode == 103 || keycode == 112 || keycode == 65307)
		manage_keycode(keycode, frame);
	if (on == NULL)
		mouvement_cam(keycode);
	else if (on->type == 's')
		mouvement_sphere(keycode, (t_sphere*)on->content);
	else if (on->type == 'y')
		mouvement_cylinder(keycode, (t_cylinder*)on->content);
	else if (on->type == 'a')
		mouvement_square(keycode, (t_square*)on->content);
	else if (on->type == 'p')
		mouvement_plane(keycode, (t_plane*)on->content);
	else if (on->type == 't')
		mouvement_triangle(keycode, (t_triangle*)on->content);
	else if (on->type == 'l')
		mouvement_light(keycode, (t_light*)on->content);
	next_frame(frame);
	mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.mlx_win,
			frame->img.img, 0, 0);
	return (0);
}

int			windows_key(t_param_frame *frame)
{
	(void)frame;
	mlx_destroy_image(frame->mlx.mlx, frame->img.img);
	mlx_destroy_window(frame->mlx.mlx, frame->mlx.mlx_win);
	ft_lstclear(g_mem_lst, free);
	free(g_mem_lst);
	exit(0);
	return (0);
}

int			minimalize(t_param_frame *frame)
{
	next_frame(frame);
	mlx_put_image_to_window(frame->mlx.mlx,
			frame->mlx.mlx_win, frame->img.img, 0, 0);
	return (0);
}

void		main_mlx(t_mlx mlx, t_img img)
{
	t_param_frame		*frame;

	if (!(frame = (t_param_frame*)malloc(sizeof(t_param_frame) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	g_rt.cam = get_next_cam(g_rt.cam);
	frame->mlx = mlx;
	frame->img = img;
	next_frame(frame);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_mouse_hook(mlx.mlx_win, clic_image, frame);
	mlx_key_hook(mlx.mlx_win, move_sth, frame);
	mlx_hook(mlx.mlx_win, 33, 1L << 17, windows_key, frame);
	mlx_expose_hook(mlx.mlx_win, minimalize, frame);
	mlx_loop(mlx.mlx);
}
