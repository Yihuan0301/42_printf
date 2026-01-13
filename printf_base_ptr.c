/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihzhang <yihzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:14:39 by yihzhang          #+#    #+#             */
/*   Updated: 2025/11/21 23:10:36 by yihzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_base(uintptr_t num, char *base, size_t base_len)
{
	size_t	count;

	count = 0;
	if (num >= base_len)
		count += ft_putptr_base(num / base_len, base, base_len);
	count += printf_char(base[num % base_len]);
	return (count);
}

int	printf_base_ptr(uintptr_t nbr, char *base, size_t base_len)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
	{
		count += printf_str("(nil)");
		return (count);
	}
	count += printf_str("0x");
	count += ft_putptr_base(nbr, base, base_len);
	return (count);
}
