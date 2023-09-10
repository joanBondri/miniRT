/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_cool_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanb <jbondri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:49:25 by joanb             #+#    #+#             */
/*   Updated: 2021/02/10 13:51:42 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			normalize_vector(t_vec tab)
{
	double	x;
	double	y;
	double	z;
	double	hyp;

	x = tab.x;
	y = tab.y;
	z = tab.z;
	if (!x && !y && !z)
		ft_exit("Error 22 : all vector at 0", 22);
	hyp = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	tab.x = x / hyp;
	tab.y = y / hyp;
	tab.z = z / hyp;
	return (tab);
}

double			extract_coo(char **str)
{
	double	u;

	u = ft_atoi_f(*str);
	if (**str == '+' || **str == '-')
		(*str)++;
	*str = afterset(*str, "0123456789");
	if (**str == '.')
		(*str)++;
	*str = afterset(*str, "0123456789");
	return (u);
}

t_vec			get_coordinate(char *coordinates)
{
	char		*str;
	t_vec		tab;

	str = coordinates;
	if (!str)
		ft_exit("Error 22 : coordinates error", 22);
	tab.x = extract_coo(&str);
	if (*str++ != ',')
		ft_exit("Error 22 : wrong coordinates input", 22);
	tab.y = extract_coo(&str);
	if (*str++ != ',')
		ft_exit("Error 22 : wrong coordinates input", 22);
	tab.z = extract_coo(&str);
	if (*str != '\0')
		ft_exit("Error 22 : wrong coordinates input", 22);
	return (tab);
}

void			add_item_list(void *content, t_list **list)
{
	t_list		*new_item;

	if (!(new_item = (t_list*)ft_malloc(sizeof(t_list) * (1))))
		ft_exit("Error 12 : Cannot allocate memory", 12);
	new_item->content = content;
	ft_lstadd_front(list, new_item);
}

void			get_color(char *colors, int tab[3])
{
	int		i;
	char	*str;

	i = -1;
	str = colors;
	if (!str)
		ft_exit("Error 22 : Wrong color input", 22);
	while (++i < 3)
	{
		tab[i] = ft_atoi(str);
		if (*str == '+' || *str == '-')
			str++;
		str = afterset(str, "0123456789");
		if ((tab[i] < 0 || tab[i] > 255) || (*str != ',' && i < 2)
				|| (*str != '\0' && i == 2))
		{
			ft_exit("Error 22 : color param is incorrect", 22);
		}
		if (*str)
			str++;
	}
}
