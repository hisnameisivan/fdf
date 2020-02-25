/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:53:58 by waddam            #+#    #+#             */
/*   Updated: 2020/02/06 01:22:56 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Upper-case character test. Returns zero if the character tests false and
** returns non-zero if the character tests true
*/

int		ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
