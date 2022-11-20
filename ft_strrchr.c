/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:07:21 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/11/14 12:07:24 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp;

	i = 0;
	temp = (char)c;
	while (s[i])
		i++;
	while (i-- && s[i])
	{
		if (s[i] == temp)
			return ((char *)s + i);
	}
	if (c == 0)
		return ((char *)s + i);
	return (NULL);
}
