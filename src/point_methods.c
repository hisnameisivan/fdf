/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:40:19 by ivan              #+#    #+#             */
/*   Updated: 2020/09/30 01:50:41 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	delta(t_point p1, t_point p2)
{
	t_point	d;

	d.x = (p2.x - p1.x) < 0 ? -(p2.x - p1.x) : (p2.x - p1.x);
	d.y = (p2.y - p1.y) < 0 ? -(p2.y - p1.y) : (p2.y - p1.y);
	return (d);
}

t_point	sign(t_point p1, t_point p2)
{
	t_point	s;

	s.x = (p2.x - p1.x) < 0 ? -1 : 1;
	s.y = (p2.y - p1.y) < 0 ? -1 : 1;
	return (s);
}

void	inc(t_point *p1, t_point *p2)
{
	p1->x += p2->x;
	p1->y += p2->y;
}
