/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contentdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:24:15 by waddam            #+#    #+#             */
/*   Updated: 2019/12/04 00:06:49 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Free memory after overwriting (for ft_lstdel)
*/

#include "libft.h"

void	ft_contentdel(void *content, size_t size)
{
	unsigned char	*temp;

	if (content)
	{
		temp = (unsigned char *)content;
		while (size > 0)
		{
			*temp = 0;
			temp++;
			size--;
		}
		free(content);
	}
}
