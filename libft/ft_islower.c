/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:56:19 by waddam            #+#    #+#             */
/*   Updated: 2020/02/06 01:21:42 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lower-case character test. Returns zero if the character tests false and
** returns non-zero if the character tests true
*/

int		ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
