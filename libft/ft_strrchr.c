/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:10:24 by waddam            #+#    #+#             */
/*   Updated: 2020/02/03 00:07:14 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp_s;
	char	*result;

	temp_s = (char *)s;
	result = NULL;
	if (c == 0)
	{
		while (*temp_s)
			temp_s++;
		return (result = temp_s);
	}
	while (*temp_s)
	{
		if (*temp_s == c)
			result = temp_s;
		temp_s++;
	}
	return (result);
}
