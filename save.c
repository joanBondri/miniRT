/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:31:09 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:54:13 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <sys/stat.h>
#include <fcntl.h>

void	put_unbr_bmp(int i, int fd, int nbr)
{
	union u_convert		conv;

	conv.size = i;
	write(fd, conv.s, nbr);
}

void	put_nbr_bmp(int i, int fd, int nbr)
{
	union u_convert		conv;

	conv.data = i;
	write(fd, conv.c, nbr);
}

void	print_data(int fd, int zero)
{
	t_vec		ray;
	t_pixel		data;
	int			i;
	int			j;
	t_vec		g;

	i = g_rt.r[1] + 1;
	while (--i > 0)
	{
		j = -1;
		while (++j < g_rt.r[0])
		{
			ray = setup(j, i);
			colision(ray, &data);
			g = gen_p(g_rt.cam->coo, ray, data.res);
			if (data.res == -1)
				data.color = 10;
			else
				data.color = get_color_light(g, data.obj);
			put_unbr_bmp(data.color, fd, 3);
		}
		j = -1;
		while (++j < zero)
			write(fd, "\0", 1);
	}
}

void	save(void)
{
	int					fd;
	int					zero;

	g_rt.cam = get_next_cam(g_rt.cam);
	fd = open("miniRT.bmp", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		ft_exit("Error 2 : save doesn't work", 2);
	write(fd, "BM", 2);
	zero = 0;
	if ((g_rt.r[0] * 3) % 4 != 0)
		zero = 4 - ((g_rt.r[0] * 3) % 4);
	put_unbr_bmp(54 + g_rt.r[1] * (g_rt.r[0] * 3 + zero), fd, 4);
	put_unbr_bmp(0, fd, 2);
	put_unbr_bmp(0, fd, 2);
	put_unbr_bmp(54, fd, 4);
	put_unbr_bmp(40, fd, 4);
	put_nbr_bmp(g_rt.r[0], fd, 4);
	put_nbr_bmp(g_rt.r[1], fd, 4);
	write(fd, "\x1\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
	write(fd, "\0\0\0\0", 4);
	print_data(fd, zero);
	close(fd);
	ft_lstclear(g_mem_lst, free);
	free(g_mem_lst);
	exit(0);
}
