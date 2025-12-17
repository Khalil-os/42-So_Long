/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:54:22 by kriad             #+#    #+#             */
/*   Updated: 2025/11/30 19:41:43 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_format(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigne(va_arg(arg, unsigned int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(arg, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

static int	ft_print_format2(const char *s, va_list arg, int *count, int *i)
{
	int	ret;

	ret = 0;
	if (s[*i] == '%' && s[*i + 1])
	{
		ret = ft_format(arg, s[*i + 1]);
		if (ret == -1)
			return (-1);
		*count += ret;
		*i += 2;
		return (0);
	}
	if (s[*i] != '%')
	{
		ret = ft_putchar(s[*i]);
		if (ret == -1)
			return (-1);
	}
	else
		return (-1);
	*count += ret;
	(*i)++;
	return (0);
}

static int	ft_print_format(const char *s, va_list arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_print_format2(s, arg, &count, &i) == -1)
			return (-1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	if (!s || write(1, "", 0) == -1)
		return (-1);
	va_start(args, s);
	count = ft_print_format(s, args);
	va_end(args);
	return (count);
}
