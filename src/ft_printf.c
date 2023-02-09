/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:30:50 by franmart          #+#    #+#             */
/*   Updated: 2023/02/09 11:08:42 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

int	ft_check_arg(char flag, va_list args)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (flag == 'x' || flag == 'p')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (flag == 'c')
		len += ft_parse_char(va_arg(args, int));
	if (flag == 's')
		len += ft_parse_str(va_arg(args, char *));
	if (flag == 'i' || flag == 'd')
		len += ft_parse_nbr(va_arg(args, int), base, flag);
	if (flag == 'x' || flag == 'X')
		len += ft_parse_nbr(va_arg(args, unsigned int), base, flag);
	if (flag == 'p')
		len += ft_parse_nbr(va_arg(args, unsigned long long), base, flag);
	if (flag == 'u')
		len += ft_parse_nbr(va_arg(args, unsigned int), base, flag);
	if (flag == '%')
		len += ft_parse_char('%');
	return (len);
}
