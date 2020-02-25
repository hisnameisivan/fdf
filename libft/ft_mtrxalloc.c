/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:37:57 by waddam            #+#    #+#             */
/*   Updated: 2020/02/11 00:34:34 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates and returns a matrix. NULL at the end of dim. "set" for ft_memset
*/

#include "libft.h"

void		**ft_mtrxalloc(int dim1, int dim2, int c,
												void *set(void *, int, size_t))
{
	int		i;
	void	**matrix;

	i = 0;
	if (!(matrix = malloc(sizeof(void *) * (dim2 + 1))))
		return (NULL);
	while (i < dim2)
	{
		if (!(matrix[i] = malloc(dim1)))
		{
			while (--i >= 0)
			{
				free(matrix[i]);
				matrix[i] = NULL;
			}
			free(matrix);
			return (NULL);
		}
		if (set)
			set(matrix[i], c, dim1);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
