/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:05:04 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 19:23:03 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	len;

	if (s && f)
	{
		len = 0;
		while (*(s + len))
			len++;
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
