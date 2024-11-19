/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:01:56 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 20:14:36 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		nbrlen(int n);
int		print_char(char c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		print_str(char *s);
void	ft_putnbr(int n);
int		print_nbr(int n);
int		print_unsigned(int n);
int		print_ptr(unsigned long long ptr);
int		print_hex(unsigned long nbr);
int		print_hex_upper(unsigned long nbr);
int		str_format(va_list args, const char str);
int		ft_printf(const char *str, ...);

#endif