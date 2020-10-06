/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:24:13 by waddam            #+#    #+#             */
/*   Updated: 2020/10/03 14:57:10 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <mlx.h>
# include <libft.h>
# include <math.h>

# define WIDTH		1600
# define HEIGHT		900
# define SCALE		40
# define MOVE_STEP	9

# define IMG_FILL	0x101110
# define RED		0xff0000
# define BLUE		0x0000ff

# define KEY_ESC	0xff1b
# define KEY_PLUS	0x003d
# define KEY_MINUS	0x002d
# define KEY_I		0x0069
# define KEY_P		0x0070
# define KEY_LEFT	0xff51
# define KEY_UP		0xff52
# define KEY_RIGHT	0xff53
# define KEY_DOWN	0xff54

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_draw
{
	t_point			delta;
	t_point			sign;
	t_point			pd;
	int				err_limit;
	int				err_step;
}					t_draw;

typedef struct		s_map
{
	int				width;
	int				height;
	t_point			*ar_pnts;
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
	int				scale;
	int				iso;
	int				move_x;
	int				move_y;
	t_map			*map;
}					t_params;

void				panic(char *msg, t_point **points, t_map *map);
void				free_multiline(char ***multiline);
void				memintset(void *b, int c, size_t len);

int					read_map(int fd, t_map *map, t_point **point);

int					parsing(char **z_line, t_point **begin, t_map *map);

t_point				*create_point(int x, int y, int z, int color);
void				add_point(t_point **begin, t_point *point);
int					convert_points(t_point *points, t_map *map);
void				destroy_points(t_point **begin);

void				draw(t_map *map, t_params *fdf);

void				alignment(t_params *params,
						t_map *map, t_point *p1, t_point *p2);

int					key_hook(int keycode, void *param);

t_point				delta(t_point p1, t_point p2);
t_point				sign(t_point p1, t_point p2);
void				inc(t_point *p1, t_point *p2);

#endif
