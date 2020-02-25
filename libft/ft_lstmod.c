/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 00:00:57 by waddam            #+#    #+#             */
/*   Updated: 2019/12/04 00:06:15 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a copy of the node with uppercase content (for ft_lstmap)
*/

#include "libft.h"

t_list	*ft_lstmod(t_list *elem)
{
	t_list			*lst;
	size_t			i;
	unsigned char	*c_lst;
	unsigned char	*c_elem;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(lst->content = malloc(elem->content_size + sizeof(char))))
		lst->content_size = 0;
	else
		lst->content_size = elem->content_size + sizeof(char);
	i = 0;
	c_lst = (unsigned char *)(lst->content);
	c_elem = (unsigned char *)(elem->content);
	while (i < (size_t)lst->content_size)
	{
		c_lst[i] = (unsigned char)ft_toupper((int)c_elem[i]);
		i++;
	}
	lst->next = NULL;
	return (lst);
}
