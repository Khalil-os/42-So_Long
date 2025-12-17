/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:10:04 by kriad             #+#    #+#             */
/*   Updated: 2025/11/10 15:31:26 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_sign(const char *str, int *j, int *sign)
{
	int	i;

	i = *j;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	*j = i;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	n;

	i = 0;
	sign = 1;
	result = 0;
	check_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = result;
		result = result * 10 + (str[i] - '0');
		if (n > result / 10 && sign == 1)
			return (-1);
		if (n > result / 10 && sign == -1)
			return (0);
		i++;
	}
	return ((int)(result * sign));
}
