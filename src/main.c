/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:24:16 by waddam            #+#    #+#             */
/*   Updated: 2020/09/30 03:57:02 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_map(void *map, size_t size)
{
	ft_bzero(map, size);
}

static int	init_params(t_params *p, t_map *map)
{
	if (WIDTH <= 0 || HEIGHT <= 0 || SCALE <= 0)
		return (-1);
	if (!(p->connect = mlx_init()))
		return (-1);
	if (!(p->window = mlx_new_window(p->connect, WIDTH, HEIGHT, "fdf")))
		return (-1);
	if (!(p->image = mlx_new_image(p->connect, WIDTH, HEIGHT)))
		return (-1);
	if (!(p->img_data = (int *)mlx_get_data_addr(p->image,
	&(p->bits_per_pixel), &(p->size_line), &(p->endian))))
		return (-1);
	p->scale = SCALE;
	p->iso = 0;
	p->move_x = 0;
	p->move_y = 0;
	p->map = map;
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_point		*points;
	t_map		map;
	t_params	params;

	points = NULL;
	init_map(&map, sizeof(t_map));
	if (argc != 2)
		panic("Usage ./fdf <path_to_map/map_name>", &points, &map);
	if (!(fd = open(argv[1], O_RDONLY)))
		panic("ERROR: couldn't open input file", &points, &map);
	if (read_map(fd, &map, &points) == -1)
		panic("ERROR: couldn't read input file", &points, &map);
	if (close(fd) == -1)
		ft_putendl_fd("WARNING: failed to close input file", 2);
	if (init_params(&params, &map) == -1)
		panic("ERROR: failed to initialize params", &points, &map);
	if (convert_points(points, &map) == -1)
		panic("ERROR: couldn't convert points list to array", &points, &map);
	destroy_points(&points);
	draw(&map, &params);
	mlx_key_hook(params.window, key_hook, &params);
	mlx_loop(params.connect);
	return (0);
}
