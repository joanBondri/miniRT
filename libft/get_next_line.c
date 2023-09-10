/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:55:35 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/01 18:01:59 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define OK 1
#define ERROR -1
#define END 0
#define ALL_LINE -1

char		*create_newline(char ***line)
{
	int		y;
	char	*new_line;

	y = 0;
	while ((**line)[y])
		y++;
	if (!(new_line = (char*)malloc(sizeof(char) * (y + 1))))
		return (NULL);
	y = -1;
	while ((**line)[++y])
		new_line[y] = (**line)[y];
	new_line[y] = '\0';
	return (new_line);
}

int			assign(char ***line, char *x)
{
	int		i;
	int		y;
	char	*new_line;

	if (!(new_line = create_newline(line)))
		return (ERROR);
	i = 0;
	while (x[i] && !is_n(x[i]))
		i++;
	y = 0;
	while ((**line)[y])
		y++;
	free(**line);
	if (!(**line = malloc(sizeof(char) * (y + i + 1))))
		return (ERROR);
	y = -1;
	while (new_line[++y])
		(**line)[y] = new_line[y];
	free(new_line);
	i = -1;
	while (x[++i] && !is_n(x[i]))
		(**line)[y + i] = x[i];
	(**line)[y + i] = '\0';
	return (is_n(x[i]) ? (i + 1) : 0);
}

int			recurs(int fd, char **line)
{
	static char		x[BUFFER_SIZE + 1] = "";
	int				res;
	int				i;

	res = assign(&line, (char *)&(x));
	if (res == 0)
	{
		res = read(fd, x, BUFFER_SIZE);
		if (res == -1)
		{
			free(*line);
			*line = NULL;
			return (ERROR);
		}
		x[res] = '\0';
		if (res == 0)
			return (END);
		return (recurs(fd, line));
	}
	i = -1;
	while (++i < BUFFER_SIZE + 1 - res)
		x[i] = x[i + res];
	while (++i < BUFFER_SIZE + 1)
		x[i] = '\0';
	return (OK);
}

int			get_next_line(int fd, char **line)
{
	int			res;

	if (fd < 0 || fd > 180 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	if (!(*line = (char*)malloc(sizeof(char) * (1))))
		return (ERROR);
	*line[0] = '\0';
	res = recurs(fd, line);
	if (res == END)
		return (END);
	return (res);
}
