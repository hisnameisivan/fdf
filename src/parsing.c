/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:59:12 by draudrau          #+#    #+#             */
/*   Updated: 2020/09/30 03:18:00 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	pre_isnan(const char **str, int base)
{
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
		(*str)++;
	if ((base == 2
	&& ft_strncmp(*str, "0b", 2) == 0)
	|| (base == 16
	&& (ft_strncmp(*str, "0x", 2) == 0 || ft_strncmp(*str, "0X", 2) == 0)))
		(*str) += 2;
}

static int	isnan_base(const char *str, int base)
{
	if (base >= 2 && base <= 16 && str)
	{
		pre_isnan(&str, base);
		while ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
		{
			if (((*str > base + '0') && base <= 10)
			|| (ft_islower(*str) && (*str - 'a' > base + '0') && base <= 16)
			|| (ft_isupper(*str) && (*str - 'A' > base + '0') && base <= 16))
				break ;
			str++;
		}
		if (*str == '\0')
			return (0);
	}
	return (1);
}

static int	count_str(char **str_array)
{
	int		count;

	count = 0;
	if (str_array)
		while (*(str_array + count))
			count++;
	return (count);
}

static int	check_z(char *z_str, int *z_val, int *color)
{
	char	**z_data;

	if (!(z_data = ft_strsplit(z_str, ',')) || count_str(z_data) > 2)
	{
		if (count_str(z_data) > 2)
			free_multiline(&z_data);
		return (-1);
	}
	if (isnan_base(z_data[0], 10) || (z_data[1] && isnan_base(z_data[1], 16)))
	{
		free_multiline(&z_data);
		return (-1);
	}
	*z_val = ft_atoi(z_data[0]);
	*color = z_data[1] ? ft_atoi_base(z_data[1], 16) : -1;
	free_multiline(&z_data);
	return (0);
}

int			parsing(char **z_line, t_point **begin, t_map *map)
{
	int		width;
	int		color;
	int		z;
	t_point	*point;

	width = 0;
	while (*(z_line + width))
	{
		if ((check_z(*(z_line + width), &z, &color) == -1)
		|| !(point = create_point(0, 0, z, color)))
			return (-1);
		add_point(begin, point);
		width++;
	}
	if (map->height == 0)
		map->width = width;
	if (map->width != width)
		return (-1);
	map->height++;
	return (0);
}
