/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:30:50 by franmart          #+#    #+#             */
/*   Updated: 2022/12/10 17:26:11 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_check_arg(char c, va_list args)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'c')
		len += ft_parse_char(va_arg(args, int));
	if (c == 's')
		len += ft_parse_str(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		len += ft_parse_nbr(va_arg(args, int), base, c);
	if (c == 'x' || c == 'X')
		len += ft_parse_nbr(va_arg(args, unsigned int), base, c);
	if (c == 'p')
		len += ft_parse_nbr(va_arg(args, unsigned long long), base, c);
	if (c == 'u')
		len += ft_parse_nbr(va_arg(args, unsigned int), base, c);
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

/*
int	main(void)
{
	int	j;
	int	i;

	i = 0;	
	j = ft_printf(" %d ", 0);
	i = printf(" %d ", 0);
	printf("\nMia: %d\nBuena:%d", j, i);
	return (0);
}
*/