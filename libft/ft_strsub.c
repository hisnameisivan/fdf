/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:16:05 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 02:46:00 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s)
	{
		i = 0;
		if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len && *s)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	else
		return (NULL);
}
