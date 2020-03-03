/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:55:07 by waddam            #+#    #+#             */
/*   Updated: 2020/03/03 23:02:56 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_multiline(char **multiline)
{
	int		i;

	i = 0;
	if (multiline)
	{
		while (multiline[i])
		{
			free(multiline[i]);
			i++;
		}
	}
	free(multiline);
}
