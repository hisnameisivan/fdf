/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:56:04 by waddam            #+#    #+#             */
/*   Updated: 2020/09/30 03:37:09 by ivan             ###   ########.fr       */
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
		*begin = NULL;
	}
}

int			convert_points(t_point *points, t_map *map)
{
	t_point	*temp;
	int		count_points;
	int		x;
	int		y;

	temp = points;
	count_points = map->width * map->height;
	if (!(map->ar_pnts = (t_point *)malloc(sizeof(t_point) * count_points)))
		return (-1);
	y = map->height - 1;
	while (temp)
	{
		count_points--;
		x = count_points % map->width;
		map->ar_pnts[count_points].x = x;
		map->ar_pnts[count_points].y = y;
		map->ar_pnts[count_points].z = temp->z;
		map->ar_pnts[count_points].color = temp->color;
		if (x == 0)
			y--;
		temp = temp->next;
	}
	if (temp)
		return (-1);
	return (0);
}
