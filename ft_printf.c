/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihzhang <yihzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:28:33 by yihzhang          #+#    #+#             */
/*   Updated: 2025/11/21 23:31:26 by yihzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_putspf(char c, va_list args)
{
	int		count;
	char	*lhex;
	char	*hhex;

	lhex = "0123456789abcdef";
	hhex = "0123456789ABCDEF";
	count = 0;
	if (c == 'c')
		count += printf_char((char)va_arg(args, int));
	else if (c == '%')
		count += printf_char('%');
	else if (c == 's')
		count += printf_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += printf_base_nbr(va_arg(args, int), "0123456789", 10, c);
	else if (c == 'u')
		count += printf_base_nbr(va_arg(args, unsigned), "0123456789", 10, c);
	else if (c == 'x')
		count += printf_base_nbr(va_arg(args, unsigned), lhex, 16, c);
	else if (c == 'X')
		count += printf_base_nbr(va_arg(args, unsigned), hhex, 16, c);
	else if (c == 'p')
		count += printf_base_ptr(va_arg(args, uintptr_t), lhex, 16);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	char	*spf;
	va_list	args;
	int		i;
	int		count;

	spf = "cspdiuxX%";
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_in_str(spf, str[i + 1]))
		{
			count += ft_putspf(str[i + 1], args);
			i++;
		}
		else
		{
			count += printf_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
