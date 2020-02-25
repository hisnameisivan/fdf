/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:19:14 by waddam            #+#    #+#             */
/*   Updated: 2020/02/05 23:49:13 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the position (index) of the first occurrence of the char in a string.
** Return -1 if the char was not found or str == NULL.
*/

int		ft_strpos(const char *str, char c)
{
	int		len;

	if (str == NULL)
		return (-1);
	len = 0;
	while (*(str + len) && *(str + len) != c)
		len++;
	if (*(str + len) != c)
		return (-1);
	return (len);
}
