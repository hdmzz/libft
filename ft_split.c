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

static int	ft_isseparator(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_wordlen(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isseparator(str[i], sep))
		i++;
	return (i);
}

static int	ft_count_words(char const *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		i = ft_wordlen(str, sep);
		if (i)
			count++;
		str += i;
	}
	return (count);
}

static char	*ft_wordup(char	const *str, int len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = 0;
	while (len--)
		temp[len] = str[len];
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		wordcount;
	int		i;
	int		j;

	wordcount = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (wordcount + 1));
	j = 0;
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isseparator(*s, c))
			s++;
		i = ft_wordlen(s, c);
		if (i)
			split[j] = ft_wordup(s, i);
		s += i;
		j++;
	}
	split[j] = NULL;
	return (split);
}
