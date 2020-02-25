/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:36:25 by waddam            #+#    #+#             */
/*   Updated: 2019/11/12 22:26:38 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	limit;

	sign = 1;
	result = 0;
	limit = FT_LONG_MAX / 10;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > limit || (result == limit && *str > '7')) && sign == 1)
			return (-1);
		if ((result > limit || (result == limit && *str > '8')) && sign == -1)
			return (0);
		result = result * 10 + (*str++ - '0');
	}
	return ((int)(sign * result));
}
