/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:16:39 by kriad             #+#    #+#             */
/*   Updated: 2025/11/10 15:47:18 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long num)
{
	int	count;

	count = 0;
	if (num <= 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		count;
	char	*str;

	nbr = (long)n;
	count = count_digits(nbr);
	str = malloc (count + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[count] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--count] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
