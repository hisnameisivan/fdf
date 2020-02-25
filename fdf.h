/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:24:13 by waddam            #+#    #+#             */
/*   Updated: 2020/02/25 23:28:25 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT		1080
# define WIDTH		1920
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_point		*next;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
}						t_map;

typedef struct			s_params
{
	void				*connect;
	void				*window;
	void				*image;
	int					*img_data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_params;

int						read_map(int fd, t_map *map);

#endif
