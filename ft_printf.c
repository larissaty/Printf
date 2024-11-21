/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:36:10 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/21 13:57:01 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		str_len;
	int			i;

	va_start (args, str);
	str_len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str [i] == '%')
		{
			str_len += str_format(args, str[i + 1]);
			i++;
		}
		else
			str_len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (str_len);
}

int	str_format(va_list args, const char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len = len + print_char(va_arg(args, int));
	if (format == 's')
		len = len + print_str(va_arg(args, char *));
	if (format == 'p')
		len = len + print_ptr(va_arg(args, unsigned long));
	if (format == 'd' || format == 'i')
		len = len + print_nbr(va_arg(args, int));
	if (format == 'u')
		len = len + print_unsigned(va_arg(args, unsigned int));
	if (format == 'x')
		len = len + print_hex(va_arg(args, unsigned int));
	if (format == 'X')
		len = len + print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
	{
		print_char('%');
		len = len + 1;
	}
	return (len);
}

// int	main(void)
// {
// 	const char	*str;
// 	char		a;
// 	int			min;

// 	str = "Teste";
// 	a = 'a';
// 	min = -42;
// 	ft_printf("%u", min);
// 	// ft_printf("Print %c, Print %s, Print %p, Print %% \n", a, str, str);
// 	return (0);
// }
