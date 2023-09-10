/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:57:53 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/10 13:49:18 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	ft_exit(char *s, int i)
{
	ft_lstclear(g_mem_lst, free);
	free(g_mem_lst);
	put_error(s, i);
}
