/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:41:19 by waddam            #+#    #+#             */
/*   Updated: 2019/11/23 04:10:21 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int		flag;
	size_t	words;

	flag = 0;
	words = 0;
	while (*s)
	{
		if (*s == c)
		{
			flag = 0;
			s++;
		}
		else
		{
			if (flag == 0)
				words++;
			flag = 1;
			s++;
		}
	}
	return (words);
}

static size_t	ft_count_chars(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_allocate_memory(size_t j, char **array, size_t len)
{
	if (!(array[j] = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (j > 0)
		{
			free(array[j - 1]);
			array[j - 1] = NULL;
			j--;
		}
		free(array);
		array = NULL;
		return (0);
	}
	else
		return (1);
}

static int		ft_words_record(size_t words, char **result, char const *s,
																		char c)
{
	size_t	i;
	size_t	j;
	size_t	chars;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		chars = ft_count_chars(&s[i], c);
		if (!(ft_allocate_memory(j, result, chars)))
			return (0);
		ft_strncpy(result[j], &s[i], chars);
		result[j][chars] = '\0';
		i += chars;
		j++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (!ft_words_record(words, result, s, c))
	{
		free(result);
		return (NULL);
	}
	result[words] = NULL;
	return (result);
}
