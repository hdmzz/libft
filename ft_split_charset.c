/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:22:32 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/06/13 14:25:41 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(int i, char *str, char *charset)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (str[i] == charset[j])
			return (0);
		j++;
	}
	return (1);
}

char	**countword(char *str, char *charset)
{
	int		i;
	int		count;
	char	**tab;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check(i, str, charset) == 0)
			i++;
		if (str[i])
			count++;
		while (str[i] && check(i, str, charset) == 1)
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	tab[count] = 0;
	return (tab);
}

char	**countchar(char *str, char *charset, char **tab)
{
	int i;
	int k;
	int count;

	count = 0;
	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check(i, str, charset) == 0)
			i++;
		while (str[i] && check(i, str, charset) == 1)
		{
			count++;
			i++;
		}
		if (count != 0)
		{
			if (!(tab[k++] = (char*)malloc(sizeof(char) * count + 1)))
				return (NULL);
			count = 0;
		}
	}
	return (tab);
}

char	**fill(char *str, char *charset, char **tab)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && check(i, str, charset) == 0)
			i++;
		while (str[i] && check(i, str, charset) == 1)
		{
			tab[k][j] = str[i];
			i++;
			j++;
		}
		if (j != 0)
			tab[k][j] = '\0';
		k++;
	}
	return (tab);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**tab;

	tab = countword(str, charset);
	tab = countchar(str, charset, tab);
	return (fill(str, charset, tab));
}
