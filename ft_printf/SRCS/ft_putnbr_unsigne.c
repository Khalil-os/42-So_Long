/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigne.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:26 by kriad             #+#    #+#             */
/*   Updated: 2025/11/30 19:54:11 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigne(unsigned int nb)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 10)
	{
		ret = ft_putnbr_unsigne(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(nb % 10 + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
