/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:30:50 by franmart          #+#    #+#             */
/*   Updated: 2024/10/13 09:39:20 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clear_buffer(t_buffer *buf);
static t_buffer	buf;

int	ft_printf(char const *str, ...)
{
	va_list			args;
	int				len;
	int				i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_arg(str[++i], args, &buf);
			i++;
		}
		else
		{
            buf.buffer[buf.index++] = str[i];
			len++;
			i++;
			if (buf.index >= BUF_SIZE)
                flush_buffer(&buf);
		}
	}
	va_end(args);
	return (len);
}

int	ft_check_arg(char flag, va_list args, t_buffer *buf)
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
		len += ft_parse_char(va_arg(args, int), buf);
	if (flag == 's')
		len += ft_parse_str(va_arg(args, char *), buf);
	if (flag == 'i' || flag == 'd')
		len += ft_parse_nbr(va_arg(args, int), base, flag, buf);
	if (flag == 'x' || flag == 'X')
		len += ft_parse_nbr(va_arg(args, unsigned long long), base, flag, buf);
	if (flag == 'p')
		len += ft_parse_nbr(va_arg(args, unsigned long long), base, flag, buf);
	if (flag == 'u')
		len += ft_parse_nbr(va_arg(args, unsigned int), base, flag, buf);
	if (flag == 'l')
		len += ft_parse_nbr(va_arg(args, unsigned long long), base, flag, buf);
	if (flag == '%')
		len += ft_parse_char('%', buf);
	return (len);
}

static void	clear_buffer(t_buffer *buf)
{
	size_t	i;

	i = -1;
	while (++i < BUF_SIZE)
		buf->buffer[i] = '\0';
}

void	flush_buffer(t_buffer *buf)
{
	if (buf->index > 0)
	{
		write(STDOUT_FILENO, buf->buffer, buf->index);
		buf->index = 0;
		clear_buffer(buf);
	}
}

void	ft_printf_flush_buffer(void)
{
	flush_buffer(&buf);
}