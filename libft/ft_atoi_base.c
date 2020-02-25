/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:58:07 by waddam            #+#    #+#             */
/*   Updated: 2019/11/20 22:11:06 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The implementation of the function atoi for base >= 2 and <= 16
*/

#include "libft.h"

static int					ft_pre_atoi(const char **str, int base)
{
	int		sign;

	sign = 1;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	if ((base == 2
	&& ft_strncmp(*str, "0b", 2) == 0)
	|| (base == 16
	&& (ft_strncmp(*str, "0x", 2) == 0 || ft_strncmp(*str, "0X", 2) == 0)))
		(*str) += 2;
	return (sign);
}

static unsigned long long	ft_result_atoi(char num, int base,
											unsigned long long result)
{
	if (num < 10 + '0' && num < base + '0')
		result = result * base + (num - '0');
	else if ((num >= 'a' && num < base + 'a' - 10)
	|| (num >= 'A' && num <= base + 'A' - 10))
		result = result * base + (num - ((num >= 'a') ? 'a' : 'A') + 10);
	return (result);
}

int							ft_atoi_base(const char *str, int base)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	limit;

	result = 0;
	limit = FT_LONG_MAX / 10;
	if (base < 2 || base > 16 || str == NULL)
		return (0);
	sign = ft_pre_atoi(&str, base);
	while ((*str >= '0' && *str <= '9')
	|| (*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
	{
		if (((*str > base + '0') && base <= 10)
		|| (ft_islower(*str) && (*str - 'a' > base + '0') && base <= 16)
		|| (ft_isupper(*str) && (*str - 'A' > base + '0') && base <= 16))
			break ;
		if ((result > limit || (result == limit && *str > '7')) && sign == 1)
			return (-1);
		if ((result > limit || (result == limit && *str > '8')) && sign == -1)
			return (0);
		result = ft_result_atoi(*str, base, result);
		str++;
	}
	return ((int)(sign * result));
}
