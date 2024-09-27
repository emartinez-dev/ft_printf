/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:20:34 by franmart          #+#    #+#             */
/*   Updated: 2024/09/27 18:38:19 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_str(char *str, t_buffer *buf)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_len(str);
	ft_putstr_buf(str, buf);
	return (len);
}

int	ft_parse_char(char c, t_buffer *buf)
{
	ft_putchar_buf(c, buf);
	return (1);
}
