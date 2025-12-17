/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:33:57 by kriad             #+#    #+#             */
/*   Updated: 2025/11/10 15:33:06 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*t;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	p = (unsigned char *)dest;
	t = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = t[i];
		i++;
	}
	return (dest);
}
