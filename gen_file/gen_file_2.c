/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_file_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:09:25 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 18:10:35 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_plane(t_plane *pl, int fd)
{
	ft_putstr_fd("pl\t\t", fd);
	put_vector_fd(pl->coo, fd);
	put_vector_fd(pl->vector, fd);
	put_color_fd(pl->color, fd);
	ft_putchar_fd('\n', fd);
}

void	put_camera(t_camera *cam, int fd)
{
	ft_putstr_fd("c\t\t", fd);
	put_vector_fd(cam->coo, fd);
	put_vector_fd(cam->vector, fd);
	ft_putnbr_fd(cam->fov, fd);
	ft_putchar_fd('\n', fd);
}

void	put_cylinder(t_cylinder *cy, int fd)
{
	ft_putstr_fd("cy\t\t", fd);
	put_vector_fd(cy->coo, fd);
	put_vector_fd(cy->vector, fd);
	put_color_fd(cy->color, fd);
	ft_putfloat_fd(cy->diameter, fd);
	ft_putchar_fd('\t', fd);
	ft_putfloat_fd(cy->heigth, fd);
	ft_putchar_fd('\n', fd);
}

void	put_triangle(t_triangle *tr, int fd)
{
	ft_putstr_fd("tr\t\t", fd);
	put_vector_fd(tr->first_coo, fd);
	put_vector_fd(tr->second_coo, fd);
	put_vector_fd(tr->third_coo, fd);
	put_color_fd(tr->color, fd);
	ft_putchar_fd('\n', fd);
}

void	put_light(t_light *l, int fd)
{
	ft_putstr_fd("l\t\t", fd);
	put_vector_fd(l->coo, fd);
	ft_putfloat_fd(l->power, fd);
	ft_putchar_fd('\t', fd);
	put_color_fd(l->color, fd);
	ft_putchar_fd('\n', fd);
}
