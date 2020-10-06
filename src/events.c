/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:28:48 by ivan              #+#    #+#             */
/*   Updated: 2020/09/30 03:29:16 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	scaling(int keycode, t_params *params)
{
	if (keycode == KEY_PLUS)
		params->scale += 1;
	if (keycode == KEY_MINUS)
	{
		params->scale -= 1;
		if (params->scale < 1)
			params->scale = 1;
	}
}

static void	change_projection_type(int keycode, t_params *params)
{
	if (keycode == KEY_I)
		params->iso = 1;
	if (keycode == KEY_P)
		params->iso = 0;
}

static void	move_img(int keycode, t_params *params)
{
	if (keycode == KEY_UP)
		params->move_y -= MOVE_STEP;
	if (keycode == KEY_DOWN)
		params->move_y += MOVE_STEP;
	if (keycode == KEY_LEFT)
		params->move_x -= MOVE_STEP;
	if (keycode == KEY_RIGHT)
		params->move_x += MOVE_STEP;
}

int			key_hook(int keycode, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (keycode == KEY_ESC)
	{
		free(params->map->ar_pnts);
		exit(0);
	}
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		scaling(keycode, params);
	if (keycode == KEY_I || keycode == KEY_P)
		change_projection_type(keycode, params);
	if (keycode == KEY_UP || keycode == KEY_DOWN
	|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_img(keycode, params);
	draw(params->map, params);
	return (0);
}
