/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:44:22 by waddam            #+#    #+#             */
/*   Updated: 2020/02/02 23:39:57 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (*(src + src_len))
		src_len++;
	while (i < len)
	{
		dst[i] = (i < src_len ? src[i] : '\0');
		i++;
	}
	return (dst);
}
