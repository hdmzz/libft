/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:22:05 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/11/18 13:22:08 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 100)
		ft_putnbr_fd(nbr / 10, fd);
	else if ((nbr / 10) > 0)
		ft_putchar_fd((nbr / 10) + '0', fd);
	ft_putchar_fd((nbr % 10 + '0'), fd);
}
