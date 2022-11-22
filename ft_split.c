/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:24:28 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/11/14 14:24:31 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static char	**ft_free(char **res)
{
	int		i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}

static char	**ft_splitwords(char **res, char const *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			res[i] = (char *)malloc((s - tmp + 1));
			if (!(res[i]))
				return (ft_free(res));
			ft_strlcpy(res[i++], tmp, s - tmp + 1);
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	ft_splitwords(res, s, c);
	return (res);
}
