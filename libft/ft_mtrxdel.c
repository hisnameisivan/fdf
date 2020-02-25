/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 00:08:57 by waddam            #+#    #+#             */
/*   Updated: 2020/02/11 00:36:56 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the address of a memory area (matrix) that needs to be
** freed, then puts the pointer to NULL
*/

#include "libft.h"

void	ft_mtrxdel(void ***matrix, int i)
{
	while (--i >= 0)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}
