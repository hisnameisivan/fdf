/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:06:16 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 04:14:43 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int count, unsigned int num)
{
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*ft_num_record(int count, unsigned int num, char sign)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	while (count > 0)
	{
		str[count - 1] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	if (sign == '-')
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char			sign;
	int				count;
	unsigned int	temp;

	sign = '+';
	count = 1;
	temp = 0;
	if (n < 0)
	{
		temp = -n;
		sign = '-';
		count++;
	}
	else
		temp = n;
	count = ft_count_digits(count, temp);
	return (ft_num_record(count, temp, sign));
}
