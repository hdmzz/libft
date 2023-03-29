/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:11:24 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/03/29 17:12:25 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_overflow(char *nbr)
{
	int	first;
	char	*second; 

	first = ft_atoi(nbr);
	second = ft_itoa(first);
	return (ft_strcmp(nbr, second));
}
