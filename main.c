/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:09:27 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 13:46:44 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	int		fd;

	fd = check_error_terminal(argc, argv);
	if (!(g_mem_lst = malloc(sizeof(t_list*))))
		return (1);
	*g_mem_lst = mem_list_init(NULL);
	parsing(fd, (bool)(argc - 2));
	if (g_rt.bmp)
		save();
	else
		go_mlx();
	return (0);
}
