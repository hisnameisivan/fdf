/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 02:33:20 by waddam            #+#    #+#             */
/*   Updated: 2019/11/21 00:41:51 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && *alst && del)
	{
		temp = *alst;
		del(temp->content, temp->content_size);
		temp->next = NULL;
		free(temp);
		*alst = NULL;
	}
}
