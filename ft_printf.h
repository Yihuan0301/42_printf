/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihzhang <yihzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:25:43 by yihzhang          #+#    #+#             */
/*   Updated: 2025/11/21 22:50:42 by yihzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	printf_char(char c);
int	printf_str(char *str);
int	printf_base_nbr(int nbr, char *base, size_t base_len, char spf);
int	printf_base_ptr(uintptr_t nbr, char *base, size_t base_len);

#endif