/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:57:23 by waddam            #+#    #+#             */
/*   Updated: 2020/02/02 02:18:41 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Swap data from memory area s1 and s2. Their size must be the same
*/

#include "libft.h"

void	ft_memswap(void *s1, void *s2, size_t size)
{
	unsigned char	temp;

	while (size--)
	{
		if (s1 == NULL || s2 == NULL)
			return ;
		else
		{
			temp = *((unsigned char *)s1);
			*((unsigned char *)s1) = *((unsigned char *)s2);
			*((unsigned char *)s2) = temp;
			s1++;
			s2++;
		}
	}
}
