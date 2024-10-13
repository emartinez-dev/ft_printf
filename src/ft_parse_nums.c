/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:34:53 by franmart          #+#    #+#             */
/*   Updated: 2024/10/13 09:40:47 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_unsigned(unsigned long long n, char *base, int *len,
								t_buffer *buf)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n / base_len > 0)
		ft_putnbr_base_unsigned(n / base_len, base, len, buf);
	c = base[n % base_len];
	*len += 1;
	ft_putchar_buf(c, buf);
}

void	ft_putnbr_base_signed(long n, char *base, int *len, t_buffer *buf)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n < 0)
	{
		*len += 1;
		ft_putchar_buf('-', buf);
		n *= -1;
	}
	if (n / base_len > 0)
		ft_putnbr_base_signed(n / base_len, base, len, buf);
	c = base[n % base_len];
	*len += 1;
	ft_putchar_buf(c, buf);
}

int	ft_parse_nbr(unsigned long long n, char *base, char flag, t_buffer *buf)
{
	int	len;

	len = 0;
	if (flag == 'p')
		len += ft_parse_str("0x", buf);
	if (flag == 'x' || flag == 'X' || flag == 'u' || flag == 'p')
		ft_putnbr_base_unsigned(n, base, &len, buf);
	else
		ft_putnbr_base_signed(n, base, &len, buf);
	return (len);
}
