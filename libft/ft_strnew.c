/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:27:23 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 02:46:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if ((size + 1) == 0 || !(newstr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < (size + 1))
	{
		newstr[i] = '\0';
		i++;
	}
	return (newstr);
}
