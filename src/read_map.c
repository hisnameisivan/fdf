/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:11:13 by waddam            #+#    #+#             */
/*   Updated: 2020/02/29 00:53:00 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// int		nan(char *num)
// {
// 	if (num)
// 	{
// 		if (*num == '+' || *num == '-')
// 			num++;
// 		while (ft_isdigit(*num))
// 			num++;
// 	}
// 	return (1);
// }

int			count_str(char **str_array)
{
	int		count;

	count = 0;
	if (str_array)
		while (*(str_array + count))
			count++;
	return (count);
}

t_point		*create_point(char *z)
{
	char	**z_data;
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	if (!(z_data = ft_strsplit(z, ',')) || count_str(z_data) > 2)
	{
		free(point);
		return (NULL);
	}
	if (ft_atoi(z_data[0]) == 0 && ft_strlen(z_data[0]) != 1)
	{
		free(point);
		return (NULL);
	}
	return (NULL); //
}

static int	parsing(char **z_line, t_point **begin, t_map *map)
{
	int		width;

	width = 0;
	while (*(z_line + width))
	{
		// ft_lstaddb((t_list**)begin, ft_lstnew((void *)));
		width++;
	}
	if (map->height == 0)
	{
		map->width = width;
		return (0);
	}
	if (map->width != width)
		return (-1);
	*begin = NULL; //
	return (0); //
}

int			read_map(int fd, t_map *map)
{
	int		res;
	char	*line;
	char	**z_line;
	t_point	*begin;

	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(z_line = ft_strsplit(line, ' ')))
			break ;
		if (parsing(z_line, &begin, map) == -1)
			return (-1);
	}
	free(line);
	return (res);
}
