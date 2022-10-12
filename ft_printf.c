/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:30:50 by franmart          #+#    #+#             */
/*   Updated: 2022/10/12 21:58:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_check_arg(char c, va_list args)
{
	int	len;
	
	len = 0;
	if (c == 'c')
		len += ft_parse_char(va_arg(args, int));
	if (c == 's')
		len += ft_parse_str(va_arg(args, char *));
	if (c == 'i' || c == 'd' || c == 'u')
		len += ft_parse_int(va_arg(args, int));
	if (c == 'x' || c == 'X')
		len += ft_parse_hex(va_arg(args, unsigned int), c);
/*
	if (c == 'p')
		len += ft_parse_ptr(va_arg(args, void *));
*/
	//if (c == 'u')
	//	len += ft_parse_u_int(va_arg(args, unsigned int));
	if (c == '%')
		len += ft_parse_char('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_arg(str[++i], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int	j;
	int	i;
	
	j = ft_printf("%u\n", -214748364);
	i = printf("%u\n", -214748364);
	printf("Mia: %d\nBuena:%d", j, i);
	return (0);
}
