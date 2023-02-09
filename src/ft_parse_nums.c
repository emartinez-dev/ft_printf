/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:34:53 by franmart          #+#    #+#             */
/*   Updated: 2023/02/09 11:12:09 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putnbr_base_unsigned(unsigned long n, char *base, int *len)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n / base_len > 0)
		ft_putnbr_base_unsigned(n / base_len, base, len);
	c = base[n % base_len];
	*len += 1;
	ft_putchar(c);
}

void	ft_putnbr_base_signed(long n, char *base, int *len)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n < 0)
	{
		*len += 1;
		ft_putchar('-');
		n *= -1;
	}
	if (n / base_len > 0)
		ft_putnbr_base_signed(n / base_len, base, len);
	c = base[n % base_len];
	*len += 1;
	ft_putchar(c);
}

int	ft_parse_nbr(long n, char *base, char flag)
{
	int	len;

	len = 0;
	if (flag == 'p')
		len += ft_parse_str("0x");
	if (flag == 'x' || flag == 'X' || flag == 'u' || flag == 'p')
		ft_putnbr_base_unsigned(n, base, &len);
	else
		ft_putnbr_base_signed(n, base, &len);
	return (len);
}
