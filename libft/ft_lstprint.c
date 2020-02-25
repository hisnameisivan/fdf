/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:59:53 by waddam            #+#    #+#             */
/*   Updated: 2020/02/06 23:06:30 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print content of the list's node (list without loop)
*/

#include "libft.h"

void	ft_lstprint(const t_list *lst)
{
	size_t	i;
	char	*content;

	while (lst)
	{
		content = (char *)lst->content;
		if (content)
		{
			i = 0;
			while (*(content + i))
				i++;
			write(1, content, i);
			write(1, "\n", 1);
		}
		lst = lst->next;
	}
}
