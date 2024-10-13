/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:34:25 by franmart          #+#    #+#             */
/*   Updated: 2024/10/13 09:41:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERNALS_H
# define INTERNALS_H

# include <stdarg.h>
# include <unistd.h>

# define BUF_SIZE 1 * 1024

typedef struct s_buffer
{
	char	buffer[BUF_SIZE];
	int		index;
}	t_buffer;

int				ft_check_arg(char flag, va_list args, t_buffer *buf);
int				ft_parse_char(char c, t_buffer *buf);
int				ft_parse_str(char *str, t_buffer *buf);
int				ft_parse_nbr(unsigned long long n, char *base, char flag, t_buffer *buf);
unsigned int	ft_len(char *str);
void			ft_putchar_buf(char c, t_buffer *buf);
void			ft_putstr_buf(char *s, t_buffer *buf);
void			flush_buffer(t_buffer *buf);

#endif