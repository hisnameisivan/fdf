/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 01:27:56 by waddam            #+#    #+#             */
/*   Updated: 2020/01/16 01:00:47 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	result = NULL;
	i = -1;
	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		while (s1[len_s1] != '\0')
			len_s1++;
	if (s2)
		while (s2[len_s2] != '\0')
			len_s2++;
	if (!(result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (len_s1-- > 0)
		*(result + ++i) = *s1++;
	while (len_s2-- > 0)
		*(result + ++i) = *s2++;
	*(result + ++i) = '\0';
	return (result);
}
