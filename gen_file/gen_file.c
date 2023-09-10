/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:48:47 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/08 14:44:02 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		put_sphere(t_sphere *s, int fd)
{
	ft_putstr_fd("sp\t\t", fd);
	put_vector_fd(s->coo, fd);
	ft_putfloat_fd(s->r, fd);
	ft_putchar_fd('\t', fd);
	put_color_fd(s->color, fd);
	ft_putchar_fd('\n', fd);
}

t_camera	*get_next_cam2(t_camera *actual)
{
	t_list		*list;
	t_camera	*o;

	list = g_rt.cameras;
	o = (t_camera*)list->content;
	if (!o)
		return (NULL);
	if (actual == NULL)
		return (o);
	while (list->content)
	{
		o = (t_camera*)list->content;
		if (o == NULL)
			return (NULL);
		if (o == actual)
			break ;
		list = list->next;
	}
	list = list->next;
	o = (t_camera*)list->content;
	return (o);
}

void		put_objs(int fd)
{
	t_object	*oj;
	t_camera	*cam;
	t_light		*li;

	oj = NULL;
	li = NULL;
	cam = NULL;
	while ((cam = get_next_cam2(cam)))
		put_camera(cam, fd);
	while ((li = get_next_light(li)))
		put_light(li, fd);
	while ((oj = get_next_object(oj)))
	{
		if (oj->type == 's')
			put_sphere((t_sphere*)oj->content, fd);
		else if (oj->type == 'y')
			put_cylinder((t_cylinder*)oj->content, fd);
		else if (oj->type == 'a')
			put_square((t_square*)oj->content, fd);
		else if (oj->type == 't')
			put_triangle((t_triangle*)oj->content, fd);
		else if (oj->type == 'p')
			put_plane((t_plane*)oj->content, fd);
	}
}

void		put_in_file(int fd)
{
	ft_putstr_fd("R\t\t", fd);
	ft_putnbr_fd(g_rt.r[0], fd);
	ft_putchar_fd('\t', fd);
	ft_putnbr_fd(g_rt.r[1], fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("A\t\t", fd);
	ft_putfloat_fd(g_rt.a_pwr, fd);
	ft_putchar_fd('\t', fd);
	put_color_fd(g_rt.a_color, fd);
	ft_putstr_fd("\n", fd);
	put_objs(fd);
}

void		gen_file(void)
{
	static int	i = 0;
	char		*str;
	int			fd;

	if (!(str = malloc(sizeof(char) * (2))))
		return ;
	str[0] = i + '0';
	str[1] = 0;
	str = ft_strjoin(ft_strjoin("scene/new/", str), "-new.rt");
	fd = open(str, O_RDWR | O_EXCL | S_IRWXU);
	if (fd == -1)
	{
		ft_exit(strerror(errno), 1);
	}
	put_in_file(fd);
	i++;
}
