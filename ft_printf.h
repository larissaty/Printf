/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:01:56 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:18 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	    print_char(char c);
int		print_str(char *s);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ptr_len(uintptr_t ptr);
void	ft_put_ptr(uintptr_t	ptr);
int		print_ptr(unsigned long long ptr);
int		str_format(va_list args, const char str);
int		ft_printf(const char *str, ...);

#endif