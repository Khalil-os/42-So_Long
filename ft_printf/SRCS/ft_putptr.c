/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:31 by kriad             #+#    #+#             */
/*   Updated: 2025/11/30 19:59:06 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_puthexptr(unsigned long nb, char *hex)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 16)
	{
		ret = ft_puthexptr(nb / 16, hex);
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

int	ft_putptr(void *p)
{
	int	count;
	int	ret;

	count = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_puthexptr((unsigned long)p, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
