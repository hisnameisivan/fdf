/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:23:37 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 04:07:49 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	while (*(s + len))
		len++;
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
	{
		s++;
		count++;
	}
	while (*s)
		s++;
	s--;
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
	{
		s--;
		count++;
		if (count > len)
			return (0);
	}
	len = len - count;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	size_t	len;
	size_t	result_len;

	if (s == NULL)
		return (NULL);
	len = ft_len(s);
	result_len = len;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	while (len > 0)
	{
		*result++ = *s++;
		len--;
	}
	*result = '\0';
	result -= result_len;
	return (result);
}
