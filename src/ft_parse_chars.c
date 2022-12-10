/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:20:34 by franmart          #+#    #+#             */
/*   Updated: 2022/12/10 17:26:11 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_parse_str(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_len(str);
	ft_putstr(str);
	return (len);
}

int	ft_parse_char(char c)
{
	ft_putchar(c);
	return (1);
}
