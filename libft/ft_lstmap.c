/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:28:22 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/19 10:13:53 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*n_lst;
	t_list		*n_elem;

	if (!lst)
		return (NULL);
	if (!(n_lst = ft_lstnew((*f)(lst->content))))
		return (NULL);
	n_elem = n_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(n_elem->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		n_elem = n_elem->next;
		lst = lst->next;
	}
	return (n_lst);
}
