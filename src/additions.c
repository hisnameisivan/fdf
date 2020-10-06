/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:55:07 by waddam            #+#    #+#             */
/*   Updated: 2020/09/30 03:24:25 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	panic(char *msg, t_point **points, t_map *map)
{
	ft_putendl_fd(msg, 2);
	destroy_points(points);
	if (map && map->ar_pnts)
		free(map->ar_pnts);
	exit(1);
}

void	free_multiline(char ***multiline)
{
	int		i;

	i = 0;
	if (*multiline)
	{
		while ((*multiline)[i])
		{
			free((*multiline)[i]);
			i++;
		}
		free(*multiline);
		*multiline = NULL;
	}
}

void	memintset(void *b, int c, size_t len)
{
	int		*temp;

	temp = (int *)b;
	while (len > 0)
	{
		*temp = c;
		temp++;
		len--;
	}
}
