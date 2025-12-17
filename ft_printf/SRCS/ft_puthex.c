/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:18 by kriad             #+#    #+#             */
/*   Updated: 2025/11/30 19:54:50 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned int nb, char *hex)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 16)
	{
		ret = ft_puthex(nb / 16, hex);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(hex[nb % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
