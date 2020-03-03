/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:24:16 by waddam            #+#    #+#             */
/*   Updated: 2020/03/04 00:50:57 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
// #include "../includes/fdf.h"

void	panic(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	init_map(void *map, size_t size)
{
	ft_bzero(map, size);
}

int		init_settings(t_params *set)
{
	if (!(set->connect = mlx_init()))
		return (-1);
	if (!(set->window = mlx_new_window(set->connect, WIDTH, HEIGHT, "mlx_42")))
		return (-1);
	if (!(set->image = mlx_new_image(set->connect, WIDTH, HEIGHT)))
		return (-1);
	if (!(set->img_data = (int *)mlx_get_data_addr(set->image,
	&(set->bits_per_pixel), &(set->size_line), &(set->endian))))
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_point		*points;
	t_map		map;
	t_params	params;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			panic("ERROR: could not open input file");
		init_map(&map, sizeof(t_map));
		if (!(points = read_map(fd, &map)))
			panic("ERROR: could not read input file");
		if (init_settings(&params) == -1)
			panic("ERROR: failed to initialize settings");
	}
	else
		panic("Usage ./fdf <path_to_map/map_name>");
	ft_putendl("debug");
	return (0);
}
