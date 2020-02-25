/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:12:44 by waddam            #+#    #+#             */
/*   Updated: 2019/11/21 00:51:54 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Computes the len of the list (list without loop)
*/

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
