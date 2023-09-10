/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:48:05 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:04:50 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	lint(long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len_n;
	long	nbr;
	char	*str;

	nbr = (long)n;
	len_n = lint(nbr);
	if (!(str = (char*)ft_malloc(sizeof(char) * (len_n + 1))))
		return (NULL);
	str[len_n--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[len_n--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
