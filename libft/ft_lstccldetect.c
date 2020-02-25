/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstccldetect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:05:48 by waddam            #+#    #+#             */
/*   Updated: 2020/02/06 01:18:36 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function return 1 if it detects a cycle inside the given linked list,
** otherwise it returns 0
*/

int		ft_lstccldetect(const t_list *lst)
{
	t_list	*temp_lst;
	t_list	*current;
	size_t	temp_len;
	size_t	cur_len;

	if (lst == NULL)
		return (0);
	current = (t_list *)lst->next;
	cur_len = 1;
	while (current)
	{
		temp_len = 0;
		temp_lst = (t_list *)lst;
		while (temp_lst != current)
		{
			temp_len++;
			temp_lst = temp_lst->next;
		}
		if (temp_len < cur_len)
			return (1);
		cur_len++;
		current = current->next;
	}
	return (0);
}
