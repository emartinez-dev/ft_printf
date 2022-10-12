/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:21 by franmart          #+#    #+#             */
/*   Updated: 2022/10/12 21:34:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_parse_char(char c);
int	ft_parse_str(char *str);
int	ft_parse_ptr(void *ptr);
int	ft_parse_int(int i);
int	ft_parse_u_int(unsigned int u);
int	ft_parse_hex(int hex, char upper);

#endif
