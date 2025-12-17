/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:38:04 by kriad             #+#    #+#             */
/*   Updated: 2025/11/10 15:41:13 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*t;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	p = (unsigned char *)dest;
	t = (unsigned char *)src;
	if (p < t)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			p[i - 1] = t[i - 1];
			i--;
		}
	}
	return (dest);
}
