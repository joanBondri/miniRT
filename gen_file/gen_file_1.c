/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_file_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:08:16 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 18:10:31 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_abs(double f)
{
	if (f < 0)
		return (-1 * f);
	return (f);
}

void	ft_putfloat_fd(float f, int fd)
{
	float		dot;
	int			sign;

	sign = f / 1;
	if (sign == 0 && f < 0)
		write(fd, "-", 1);
	ft_putnbr_fd(sign, fd);
	dot = (float)ft_abs(f) - (float)floor(ft_abs(f));
	while (dot * 10 < INT_MAX && !(dot <= floor(dot) + 0.0001 &&
				dot >= floor(dot) - 0.0001))
		dot *= 10;
	ft_putchar_fd('.', fd);
	ft_putnbr_fd((int)dot, fd);
}

void	put_color_fd(int c[3], int fd)
{
	ft_putnbr_fd(c[0], fd);
	ft_putchar_fd(',', fd);
	ft_putnbr_fd(c[1], fd);
	ft_putchar_fd(',', fd);
	ft_putnbr_fd(c[2], fd);
	ft_putchar_fd('\t', fd);
}

void	put_vector_fd(t_vec v, int fd)
{
	ft_putfloat_fd(v.x, fd);
	ft_putchar_fd(',', fd);
	ft_putfloat_fd(v.y, fd);
	ft_putchar_fd(',', fd);
	ft_putfloat_fd(v.z, fd);
	ft_putchar_fd('\t', fd);
}

void	put_square(t_square *a, int fd)
{
	ft_putstr_fd("sq\t\t", fd);
	put_vector_fd(a->coo, fd);
	put_vector_fd(a->vector, fd);
	ft_putfloat_fd(a->border, fd);
	ft_putchar_fd('\t', fd);
	put_color_fd(a->color, fd);
	ft_putchar_fd('\n', fd);
}
