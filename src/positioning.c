/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 02:43:43 by ivan              #+#    #+#             */
/*   Updated: 2020/10/04 23:32:38 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	iso(t_point *p1, t_point *p2)
{
	int		temp_x1;
	int		temp_y1;
	int		temp_x2;
	int		temp_y2;

	temp_x1 = p1->x;
	temp_y1 = p1->y;
	temp_x2 = p2->x;
	temp_y2 = p2->y;
	p1->x = (temp_x1 - temp_y1) * cos(0.523599);
	p1->y = -(p1->z) + (temp_x1 + temp_y1) * sin(0.523599);
	p2->x = (temp_x2 - temp_y2) * cos(0.523599);
	p2->y = -(p2->z) + (temp_x2 + temp_y2) * sin(0.523599);
}

void		alignment(t_params *params, t_map *map, t_point *p1, t_point *p2)
{
	p1->x *= params->scale;
	p1->y *= params->scale;
	p1->z *= params->scale;
	p2->x *= params->scale;
	p2->y *= params->scale;
	p2->z *= params->scale;
	if (params->iso)
		iso(p1, p2);
	p1->x += (WIDTH - (map->width - 1) * params->scale) / 2 + params->move_x;
	p1->y += (HEIGHT - (map->height - 1) * params->scale) / 2 + params->move_y;
	p2->x += (WIDTH - (map->width - 1) * params->scale) / 2 + params->move_x;
	p2->y += (HEIGHT - (map->height - 1) * params->scale) / 2 + params->move_y;
}
