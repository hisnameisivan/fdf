/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:57:37 by ivan              #+#    #+#             */
/*   Updated: 2020/10/03 14:54:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		filling_image(t_params *params)
{
	memintset((void *)(params->img_data), IMG_FILL, WIDTH * HEIGHT);
}

static void		filling_pixel(t_params *params, t_point p1, t_point p2)
{
	int		i;
	int		color;

	if (p1.color != -1)
	{
		color = p1.color;
		color = (p1.z != p2.z) ? (color | BLUE) : color;
	}
	else if (p2.color != -1)
	{
		color = p1.color;
		color = (p1.z != p2.z) ? (color | BLUE) : color;
	}
	else
	{
		color = (p1.z || p2.z) ? RED : BLUE;
		color = (p1.z != p2.z) ? (RED | BLUE) : color;
	}
	if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
	{
		i = p1.x + p1.y * params->size_line / sizeof(int);
		params->img_data[i] = color;
	}
}

static t_draw	init_draw_params(t_point p1, t_point p2)
{
	t_draw	dr;

	dr.delta = delta(p1, p2);
	dr.sign = sign(p1, p2);
	if (dr.delta.x > dr.delta.y)
	{
		dr.pd.x = dr.sign.x;
		dr.pd.y = 0;
		dr.err_step = dr.delta.y;
		dr.err_limit = dr.delta.x;
	}
	else
	{
		dr.pd.x = 0;
		dr.pd.y = dr.sign.y;
		dr.err_step = dr.delta.x;
		dr.err_limit = dr.delta.y;
	}
	return (dr);
}

static void		draw_line(t_point p1, t_point p2, t_map *map, t_params *params)
{
	t_draw	dr;
	t_point	temp;
	int		err;
	int		i;

	alignment(params, map, &p1, &p2);
	dr = init_draw_params(p1, p2);
	temp = p1;
	err = dr.err_limit / 2;
	i = 0;
	filling_pixel(params, temp, p2);
	while (i < dr.err_limit)
	{
		err -= dr.err_step;
		if (err < 0)
		{
			err += dr.err_limit;
			inc(&temp, &(dr.sign));
		}
		else
			inc(&temp, &(dr.pd));
		filling_pixel(params, temp, p2);
		i++;
	}
}

void			draw(t_map *map, t_params *params)
{
	int		x;
	int		y;

	filling_image(params);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(map->ar_pnts[y * map->width + x],
					map->ar_pnts[y * map->width + x + 1], map, params);
			if (y != map->height - 1)
				draw_line(map->ar_pnts[y * map->width + x],
					map->ar_pnts[(y + 1) * map->width + x], map, params);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->connect,
		params->window, params->image, 0, 0);
}
