/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:55:21 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:51:25 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_error_terminal(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
		put_error("Error 22 : Too few argument", 22);
	if (argc > 3)
		put_error("Error 22 : Too much argument", 22);
	if (argc == 3 && ft_strncmp("-save", argv[2], ft_strlen("-save")))
		put_error("Error 22 : Invalid argument", 22);
	if (check_ext(argv[1], ".rt") == -1)
		put_error("Error 22 : Invalid argument", 22);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		put_error("Error 2 : No such file or directory", 2);
	return (fd);
}

void	put_error(const char *error_str, int i)
{
	if (error_str && *error_str)
		printf("%s\n", error_str);
	exit(i);
}
