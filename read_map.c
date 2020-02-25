/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:11:13 by waddam            #+#    #+#             */
/*   Updated: 2020/02/25 23:27:59 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




int		read_map(int fd, t_map *map)
{
	int		res;
	char	*line;
	char	**z_line;
	t_point	*begin;

	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(z_line = ft_strsplit(line, ' ')))
			break ;

	}
	return (res);
}
