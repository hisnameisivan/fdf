/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:56:04 by waddam            #+#    #+#             */
/*   Updated: 2020/03/02 00:56:53 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point		*create_point(int x, int y, int z, int color)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	point->next = NULL;
	return (point);
}

void		add_point(t_point **begin, t_point *point)
{
	if (begin && point)
	{
		point->next = *begin;
		*begin = point;
	}
}

void		destroy_points(t_point **begin)
{
	t_point	*temp1;
	t_point	*temp2;

	if (begin)
	{
		temp1 = *begin;
		while (temp1)
		{
			temp2 = temp1->next;
			free(temp1);
			temp1 = temp2;
		}
	}
}

/*
** t_point		*create_point(char *z)
** {
** 	char	**z_data;
** 	t_point	*point;
**
** 	if (!(point = (t_point *)malloc(sizeof(t_point))))
** 		return (NULL);
** 	if (!(z_data = ft_strsplit(z, ',')) || count_str(z_data) > 2)
** 	{
** 		// free_point(point); // panic?
** 		// free(point); // panic?
** 		return (NULL);
** 	}
** 	if (isnan_base(z_data[0], 10) || (z_data[1] && isnan_base(z_data[1], 16)))
** 	{
** 		// free_point(point); // panic?
** 		// free(point); // panic?
** 		return (NULL);
** 	}
** 	point->z = ft_atoi(z_data[0]);
** 	return (NULL); //
** }
*/

/*
** void		free_point(t_point *point)
** {
** 	free(point->cnt_pnts);
** 	free(point);
** 	point = NULL;
** }
*/
