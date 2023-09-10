/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_cool_function_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:16 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:51:52 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	gen_p(t_vec origin, t_vec vec, double t)
{
	return (ope(origin, '+', ope_num(vec, '*', t)));
}

void	assign_array(int tab[3], int src[3])
{
	tab[0] = src[0];
	tab[1] = src[1];
	tab[2] = src[2];
}

int		check_ext(char *file, char *ext)
{
	int		i;
	char	*file_2;

	if (ft_strlen(ext) > ft_strlen(file))
		return (-1);
	file_2 = file + ft_strlen(file) - ft_strlen(ext);
	i = ft_strlen(ext) + 1;
	while (--i)
	{
		if (ext[i] != file_2[i])
			return (-1);
	}
	return (0);
}

int		len_tab_string(char **strs)
{
	int		i;

	i = 0;
	if (!strs)
		return (-1);
	while (strs[i])
		i++;
	return (i);
}

t_vec	get_vector(char *vector)
{
	int		i;
	t_vec	tab;

	i = 0;
	tab = get_coordinate(vector);
	if (tab.x > 1.0 || tab.x < -1.0
			|| tab.y > 1.0 || tab.y < -1.0
			|| tab.z > 1.0 || tab.z < -1.0)
		ft_exit("Error 22 : wrong vector input", 22);
	return (normalize_vector(tab));
}
