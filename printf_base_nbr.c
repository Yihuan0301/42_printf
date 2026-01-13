/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihzhang <yihzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:14:39 by yihzhang          #+#    #+#             */
/*   Updated: 2025/11/21 22:44:32 by yihzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned int num, char *base, size_t base_len)
{
	size_t		count;

	count = 0;
	if (num >= base_len)
		count += ft_putnbr_base(num / base_len, base, base_len);
	count += printf_char(base[num % base_len]);
	return (count);
}

int	printf_base_nbr(int nbr, char *base, size_t base_len, char spf)
{
	size_t	count;

	count = 0;
	if ((spf == 'd' || spf == 'i') && nbr < 0)
	{
		count += printf_char('-');
		nbr = -nbr;
	}
	count += ft_putnbr_base(nbr, base, base_len);
	return (count);
}
