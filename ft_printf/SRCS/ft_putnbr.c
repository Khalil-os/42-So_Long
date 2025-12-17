/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:28 by kriad             #+#    #+#             */
/*   Updated: 2025/11/30 20:01:27 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		ret;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		count += ret;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(nb % 10 + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}
