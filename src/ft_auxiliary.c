/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:08:04 by franmart          #+#    #+#             */
/*   Updated: 2024/09/27 19:26:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_buf(char c, t_buffer *buf)
{
    buf->buffer[buf->index++] = c;
    if (buf->index >= BUF_SIZE)
        flush_buffer(buf);
}

void	ft_putstr_buf(char *str, t_buffer *buf)
{
	int	i;

	i = -1;
    while (str[++i])
    {
        buf->buffer[buf->index++] = str[i];
        if (buf->index >= BUF_SIZE)
            flush_buffer(buf);
    }
}