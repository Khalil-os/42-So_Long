/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:33 by kriad             #+#    #+#             */
/*   Updated: 2025/11/24 17:54:34 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	ret;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		ret = ft_putchar(s[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}
