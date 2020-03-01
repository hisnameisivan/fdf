/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:24:13 by waddam            #+#    #+#             */
/*   Updated: 2020/03/02 00:59:28 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT		1080
# define WIDTH		1920
# include <fcntl.h>
# include "mlx.h"
# include <libft.h>
# include <get_next_line.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				*cnt_pnts;
	struct s_point	*next;
}					t_point;

typedef struct		s_map
{
	int				width;
	int				height;
}					t_map;

typedef struct		s_params
{
	void			*connect;
	void			*window;
	void			*image;
	int				*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_params;

int					read_map(int fd, t_map *map);
int					parsing(char **z_line, t_point **begin,
												int *cnt_pnts, t_map *map);
t_point				*create_point(int x, int y, int z, int color);
void				add_point(t_point **begin, t_point *point);
void				destroy_points(t_point **begin);
// void				free_point(t_point *point);

#endif
